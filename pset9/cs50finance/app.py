import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Get user ID
    user_id = session["user_id"]
    # Get user balance
    balance = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    prices = []
    total_prices = []
    total_balance = balance
    counter = 0

    # Get all shares the user owns
    portfolio = db.execute(
        "SELECT symbol, SUM(shares) AS own_shares, company_name FROM orders WHERE fk_user_id =? GROUP BY symbol HAVING own_shares > 0", user_id)

    # Calculate Total Price and Total Balance
    for i, symbol in enumerate(portfolio):
        prices.append(lookup(symbol["symbol"])["price"])
        total_prices.append(portfolio[i]["own_shares"]*prices[i])
        total_balance += total_prices[i]
        
    return render_template("index.html", portfolio=portfolio, prices=prices, total_prices=total_prices, balance=balance, total_balance=total_balance)
    

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = lookup(request.form.get("symbol"))
        user_id = session["user_id"]

        # ensure symbol exist
        if not symbol:
            return apology("must provide symbol")

        # Ensure share number is valid
        if not request.form.get("shares").isdigit():
            return apology("Share value must be integer number")

        shares = int(request.form.get("shares"))
        
        if shares < 0:
            return apology("Share value invalid")

        # Get a symbol's share price
        price = symbol["price"]
        # Get user balance
        balance = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        # Ensure user can buy it
        final_balance = balance - (price * shares)
        if (final_balance < 0):
            return apology("not enough money")

        # Record database
        else:
            # Update User balance
            db.execute("UPDATE users SET cash = ? WHERE id = ?", final_balance, user_id)

            # get order_type_id
            type_id = db.execute("SELECT order_type_id FROM order_types WHERE order_type_text = ?", "buy")[0]["order_type_id"]
            db.execute("INSERT INTO orders (fk_user_id, fk_order_type_id, company_name, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, ?,CURRENT_TIMESTAMP)",
            user_id, type_id, symbol["name"], symbol["symbol"], shares, price)

        # Redirect user to home page
        return redirect("/")
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]

    orders = db.execute(
        "SELECT fk_order_type_id AS order_type_id, symbol, company_name, shares, price, date FROM orders WHERE fk_user_id = ?", user_id)
    
    total_price = []
    
    for i, order in enumerate(orders):
        mol = 1
        if order["shares"] < 0:
            mol *= -1
        total = order["shares"] * order["price"] * mol
        total_price.append(total)
    
    return render_template("history.html", orders=orders, total_price=total_price)
    

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password")

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        symbol = lookup(request.form.get("symbol"))

        # ensure symbol exist
        if not symbol:
            return apology("must provide symbol")

        else:
            return render_template("quoted.html", stock=symbol)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    if request.method == "POST":

        # Get request to variables
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("must provide username")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username is unique
        if len(rows) > 0:
            return apology("This username already exist")

        # Ensure password was submitted
        if not password:
            return apology("must provide password")

        # Ensure confirmation password was submitted
        if not confirmation:
            return apology("must provide confirmation password")

        # Ensure password and confirmation password is same
        if not (password == confirmation):
            return apology("password and password confirmation must be same")

        # add to database
        db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", username, generate_password_hash(password))
        newUser = db.execute("SELECT * FROM users WHERE username = ?", username)

        if newUser:
            # Remember which user has logged in
            session["user_id"] = newUser[0]["id"]

            # Redirect user to home page
            return redirect("/")

    else:
        return render_template("register.html")
        

@app.route("/settings", methods=["GET", "POST"])
@login_required
def settings():
    """Settings"""
    
    if request.method == "POST":
        user_id = session["user_id"]
        current_password = request.form.get("current")
        new_password = request.form.get("password")
        confirmation_password = request.form.get("confirmation")
        
        # Ensure current password was submitted
        if not current_password:
            return apology("must provide current password")

        # Ensure new password was submitted            
        if not new_password:
            return apology("must provide new password")
            
        # Ensure password confirmation was submitted
        if not confirmation_password:
            return apology("must provide password confirmation")
        
        # Query database for user id
        user = db.execute("SELECT * FROM users WHERE id=?", user_id)
        
        # Ensure submitted current password is same than db current password
        if not check_password_hash(user[0]["hash"], current_password):
            return apology("invalid password")
            
        # ensure new password and password confirmation is same
        if not new_password == confirmation_password:
            return apology("password and password confirmation must be same")
       
        # Update user balance
        db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(new_password), user_id)
        
        return redirect("/")
        
    else:
        user_id = session["user_id"]
        
        # Query database for user id
        username = db.execute("SELECT username FROM users WHERE id=?", user_id)[0]["username"]
        
        return render_template("settings.html", username=username)


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        user_id = session["user_id"]
        symbol_sell = lookup(request.form.get("symbol"))
        shares_sell = int(request.form.get("shares"))
        
        # ensure user select symbol
        if not symbol_sell:
            return apology("must provide symbol")
        
        # get share quantity
        symbol = symbol_sell["symbol"]
        own_shares = db.execute(
            "SELECT SUM(shares) AS shares FROM orders WHERE fk_user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)[0]["shares"]
        
        # Ensure user has this symbol share
        if not own_shares:
            return apology("you dont have this share")
        
        # ensure shares value is valid
        if shares_sell < 0:
            return apology("Share value invalid")
        
        # ensure user has shares to sell
        if own_shares < shares_sell:
            return apology("Too many shares")
            
        else:
            # Get a symbol's share price
            price = int(symbol_sell["price"])
            
            # Get user balance
            balance = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
            
            # calculate user final balance
            final_balance = balance + (price * shares_sell)
            shares_sell *= -1
            
            # Record database
            
            # Update user balance
            db.execute("UPDATE users SET cash = ? WHERE id = ?", final_balance, user_id)
            
            type_id = db.execute("SELECT order_type_id FROM order_types WHERE order_type_text = ?", "sell")[0]["order_type_id"]
            db.execute("INSERT INTO orders (fk_user_id, fk_order_type_id, company_name, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, ?,CURRENT_TIMESTAMP)",
            user_id, type_id, symbol_sell["name"], symbol_sell["symbol"], shares_sell, price)
            
            # Redirect user to home page
            return redirect("/")
        
    else:
        user_id = session["user_id"]
        
        symbols = db.execute("SELECT symbol FROM orders WHERE fk_user_id =? GROUP BY symbol", user_id)
        
        
        return render_template("sell.html", symbols=symbols)
import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        errorMessage = ""
        # TODO: Add the user's entry into the database
        
        # Ensure name is valid
        name = request.form.get("name")
        if not name:
            errorMessage = "Must provide name"
        
        # Ensure month is valid
        elif not request.form.get("month").isdigit():
            errorMessage = "Must provide month"
            
        else:
            month = int(request.form.get("month"))
            
            if month < 1 or month > 12:
                errorMessage = "Month value is not valid"
                
            # Ensure month is valid
            elif not request.form.get("day").isdigit():
                errorMessage = "Must provide day"
                
            else:
                day = int(request.form.get("day"))
                if month == 2 and day > 29:
                    errorMessage = "Day value is not valid"
                
                elif month == 4 or month == 6 or month == 9 or month == 11:
                    if day > 30:
                        errorMessage = "Day value is not valid"
        
                elif day > 31:
                        errorMessage = "Day value is not valid"
                        
                        
                if not errorMessage:
                    db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        
        rows = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", error=errorMessage, birthdays=rows)

    else:

        # TODO: Display the entries in the database on index.html
        rows = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", error="", birthdays=rows)


@app.route("/delete", methods=["POST"])
def delete():
    birth_id = request.form.get("id")
    if birth_id:
        db.execute("DELETE FROM birthdays WHERE id = ?", birth_id)
            
    return redirect("/")
        
@app.route("/update", methods=["POST"])
def edit():
    birth_id = request.form.get("id")

    errorMessage = ""
        
    # Ensure name is valid
    name = request.form.get("name")
    if not name:
        errorMessage = "Must provide name"
        
    # Ensure month is valid
    elif not request.form.get("month").isdigit():
        errorMessage = "Must provide month"
            
    else:
        month = int(request.form.get("month"))
            
        if month < 1 or month > 12:
            errorMessage = "Month value is not valid"
                
        # Ensure month is valid
        elif not request.form.get("day").isdigit():
            errorMessage = "Must provide day"
                
        else:
            day = int(request.form.get("day"))
            if month == 2 and day > 29:
                errorMessage = "Day value is not valid"
                
            elif month == 4 or month == 6 or month == 9 or month == 11:
                if day > 30:
                    errorMessage = "Day value is not valid"
    
            elif day > 31:
                    errorMessage = "Day value is not valid"
                        
                        
            if not errorMessage:
                db.execute("UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?", name, month, day, birth_id)
        
    rows = db.execute("SELECT * FROM birthdays")
    return render_template("index.html", error=errorMessage, birthdays=rows)
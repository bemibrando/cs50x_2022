# TODO
import cs50

while True:
    try:
        change = float(input("Change owed: "))
        if change > 0:
            break
    except:
        print("")
        
twentyFive = 0.25 
ten = 0.1
five = 0.05
one = 0.01

coinCounter = 0

while change > 0:
    if change >= twentyFive:
        coin = twentyFive
    elif change >= ten:
        coin = ten
    elif change >= five:
        coin = five
    elif change >= one:
        coin = one
    else:
        break
    
    result = int(change / coin)
    coinCounter += result
#    print("{}, coin: {} of {}".format(change, result, coin))
    change = round(change + (-result * coin), 2)
    
print(coinCounter)
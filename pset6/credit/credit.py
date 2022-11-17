# TODO
import sys


def get_cc_number():
    while True:
        ccNumber = input("Number: ")
        try:
            if int(ccNumber) > 0:
                break
        except:
            print("error")

    return ccNumber
    

def validate_card(ccNumber):
    ccLength = len(ccNumber)
    if ccLength != 13 and ccLength != 15 and ccLength != 16:
        print("INVALID")
        sys.exit(0)

    ccSum = 0
    
    if ccLength % 2 == 0:
        for i in range(ccLength):
            numb = int(ccNumber[i])
            if i % 2 == 0:
                mult = numb * 2
                if mult > 9:
                    ccSum += 1 + (mult - 10)
                else:
                    ccSum += mult
            else:
                ccSum += numb
                
    else:
        for i in range(ccLength):
            numb = int(ccNumber[i])
            if i % 2 == 0:
                ccSum += numb
            else:
                mult = numb * 2
                if mult > 9:
                    ccSum += 1 + (mult - 10)
                else:
                    ccSum += mult

    checkSum = ccSum % 10
    
    if checkSum != 0:
        print("INVALID")
    else:
        first_digit = int(ccNumber[0])
        second_digit = int(ccNumber[1])
        
        if (first_digit == 5) and (0 < second_digit < 6):
            print("MASTERCARD")
        elif (first_digit == 3) and (second_digit == 4 or second_digit == 7):
            print("AMEX")
        elif first_digit == 4:
            print("VISA")
        else:
            print("INVALID")


credit_card = get_cc_number()
validate_card(credit_card)
# TODO
import cs50

MAX = 8

while True:
    try: 
        height = int(input("Height: "))
        if (height >= 1) and (height <= MAX):
            break
    except:
        print("", end="")
            
for i in range(height):
    for j in range(height):
        staircase = height - i - 1
        
        if staircase <= j:
            print(" ", end="")
        else:
            print("#", end="")
    
    print()
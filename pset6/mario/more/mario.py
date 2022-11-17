# TODO
MAX = 8

while True:
    try: 
        height = int(input("Height: "))
        if (height >= 1) and (height <= MAX):
            break
    except:
        print("", end="")
        
width = height * 2 + 1

for i in range(height):
    for j in range(width):
        staircase = height - i - 1
        staircaseRev = height + i + 1
        
        if staircase > j:
            print(" ", end="")
        elif j == height:
            print("  ", end="")
        elif j > staircaseRev:
            break
        else:
            print("#", end="")
    
    print()
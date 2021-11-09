from cs50 import get_float


def main():
    owed = change_owed()
    coins = 0
    
    # Until there is no more change owed
    while (owed > 0):
        
        # Use a quarter
        if owed >= 25:
            owed = owed - 25
            coins += 1
            
        # Use a dime
        if owed >= 10 and owed < 25:
            owed = owed - 10
            coins += 1
            
        # Use a nickle
        if owed >= 5 and owed < 10:
            owed = owed - 5
            coins += 1
            
        # Use a penny
        if owed >= 1 and owed < 5:
            owed = owed - 1
            coins += 1
            
    # How many coins are needed?
    print(coins)
        

def change_owed():
    # Re-prompt the user for change owed. Must be a floating point number. Ex. 1.2; 0.45; 23;
    while True:
        owed = get_float("Change owed: ") * 100             # *100 just so we don't have to deal with decimals
        if owed > 0:
            break
    return owed
    

main()
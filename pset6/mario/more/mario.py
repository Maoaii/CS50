from cs50 import get_int


def main():
    # Retrieve the height from get_height
    height = get_height()
    
    # Go through each row
    for i in range(1, height + 1):
        
        # Left pyramid
        # Print spaces. As height increases, spaces decrease
        for j in range(height, i, -1):
            print(" ", end="")
            
        # Print "#". As height increases, number of "#"'s increases
        for k in range(i):
            print("#", end="")
            
        # Print the space between the pyramids
        print("  ", end="")
        
        # Right pyramid
        # Print "#", left-aligned. As height increases, number of "#"'s increases aswell
        for l in range(i):
            print("#", end="")
            
        # Print a newline and start new row
        print("")


# Got the height from a different function to make it easier to modulate
def get_height():
    
    # Until loop is broken, prompt for height between 1 and 8, inclusive
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break
    return height


main()
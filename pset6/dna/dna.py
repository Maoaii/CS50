from sys import argv, exit
from csv import reader, DictReader


def main():
    
    # Prompt user for the correct command-line arguments
    if len(argv) != 3:
        print("Name of CSV file followed by name of a text file containing DNA sequences")
        
    '''
            Open and store each row in a list. I can access small's database like this: STRs[0][1] gives me
        the first STR, STRs[0][2] gives me the second; STRs[1][0] gives me a person's name and STRs[1][1] gives me
        the amount of times the STRs[0][1] STR repeats in that persons DNA.

        small.csv:
             [0]                 [1]                [2]               [3]          len(database[0/1/2/3])
         __________________________________________________________________________
     [0]| [0][0] = 'name'   | [0][1] = 'AGATC' | [0][2] = 'AATG' | [0][3] = 'TATC' |
        |--------------------------------------------------------------------------|
     [1]| [1][0] = 'Alice'  | [1][1] = '2'     | [1][2] = '8'    | [1][3] = '3'    |
        |--------------------------------------------------------------------------|
     [2]| [2][0] = 'Bob'    | [2][1] = '4'     | [2][2] = '1'    | [2][3] = '5'    |
        |--------------------------------------------------------------------------|
     [3]| [3][0] = 'Charlie'| [3][1] = '3'     | [3][2] = '2'    | [3][3] = '5'    |
        |__________________________________________________________________________|
        len(database)
     
    '''

    with open(argv[1], "r") as csvfile:
        reader = DictReader(csvfile)
        database = list(reader)

    # Open and store a DNA sequence in a single list
    with open(argv[2], "r") as dnafile:
        sequence = dnafile.read()
    
    # Create array to store max counts for each STR, to, then, compare with database
    maxcounts = []
    
    # Start looping through the different types of STRs
    for i in range(1, len(reader.fieldnames)):
        STR = reader.fieldnames[i]
        maxcounts.append(0)
        
        # Loop through sequence
        for j in range(len(sequence)):
            STRcount = 0
            
            # Check if STR is in sequence
            if sequence[j:(j + len(STR))] == STR:
                k = 0
                
                # While STR gets matches in sequence, continue looking for more
                while sequence[(j + k):j + k + len(STR)] == STR:
                    STRcount += 1
                    k += len(STR)
                    
                # If that STRcount surpasses what is written in maxcounts for that same STR, overwrite it
                if STRcount > maxcounts[i - 1]:
                    maxcounts[i - 1] = STRcount
     
    # Loop through database
    for i in range(len(database)):
        matches = 0
        
        # Loop through the list with maxcounts
        for j in range(1, len(reader.fieldnames)):
            # Check if there are matches and print that person's name
            if int(maxcounts[j - 1]) == int(database[i][reader.fieldnames[j]]):
                matches += 1
                
            if matches == (len(reader.fieldnames) - 1):
                print(database[i]['name'])
                exit(0)
    
    # If there is no match, print this            
    print("No match")
            
    
main()
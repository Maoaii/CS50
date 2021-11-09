from cs50 import get_string


def main():
    
    # Input user for text
    text = get_string("Text: ")
    
    # Compute grade level
    grade = compute_grade(text)
    
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Grade " + str(grade))


# Compute grade level
def compute_grade(text):
    
    letters = 0
    words = 1       # Initialized to 1 because of the last word in the text (isn't followed by a " ")
    sentences = 0
    
    # Iterate over the text
    for c in text:
        if c.isalpha() == True:
            letters += 1
        elif c == " ":
            words += 1
        elif c == "." or c == "!" or c == "?":
            sentences += 1
    
    # Calculate average number of letters per 100 words in the text
    L = (letters * 100) / words
    # Calculate average number of sentences per 100 words in the text
    S = (sentences * 100) / words
    
    # Calculate grade level
    grade = 0.0588 * L - 0.296 * S - 15.8
    
    return round(grade)


main()
        
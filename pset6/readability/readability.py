# TODO
import sys


def get_text():
    while True:
        text = input("Text: ")
        try:
            if len(text) > 0:
                break
        except:
            print("Error")
            
    return text


def calculate_readability(text):
    count_char, count_words, count_sentences = 0, 0, 0
    
    for textChar in text:
        
        if (textChar == '!') or (textChar == '?') or (textChar == '.'):
            count_sentences += 1
        elif textChar == ' ':
            count_words += 1
        elif (textChar == '-') or (textChar == ',') or (textChar == '\'') or (textChar == '"') or (textChar == ':'):
            continue
        else:
            count_char += 1
            
    # added count of last word
    count_words += 1
    
    # index = 0.0588 * L - 0.296 * S - 15.8
    # L = the average number of letters per 100 words
    # S = the average number of sentencer per 100 words
    L = count_char / count_words * 100
    S = count_sentences / count_words * 100
    
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade {}".format(index))
    
    
text = get_text()
calculate_readability(text)
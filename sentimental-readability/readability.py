from cs50 import get_string


text = get_string("Text: ")


def letters(txt):
    sum = 0
    for char in txt:
        if char.isalpha():
            sum += 1
    return sum


def words(txt):
    sum = 1
    for char in txt:
        if char == ' ':
            sum += 1
    return sum


def sentences(txt):
    sum = 0
    for char in txt:
        if char == '.' or char == '!' or char == '?':
            sum += 1
    return sum


index = round((5.88 * letters(text)) / words(text) - (29.6 * sentences(text)) / words(text) - 15.8)

if index < 1:
    print("Before Grade 1")
if index >= 16:
    print("Grade 16+")
if index > 1 and index < 16:
    print(f"Grade {index}")

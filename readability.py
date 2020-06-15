from cs50 import get_int, get_string


def main():
    text = get_string("Insert text: ")

    num_letters = count_letters(text)
    num_words = count_words(text)
    num_sentences = count_sentences(text)

    l = (num_letters / num_words) * 100  # calculates the average number of letters per 100 words
    s = (num_sentences / num_words) * 100  # calculates the average number of sentences per 100 words

    index = round(0.0588 * l - 0.296 * s - 15.8)  # formula

    if index < 1:
        print("Before Grade 1")

    elif index >= 16:
        print("Grade 16+")

    else:
        print("Grade", int(index))


def count_letters(s):  # function count letters

    letters = 0

    for char in s:
        if (char.isalpha()) == True:
            letters += 1

    return letters


def count_words(s):  # function count words

    text_split = s.split()

    words = 0

    for Word in text_split:
        words += 1

    return words


def count_sentences(s):  # function count sentences

    sentence = 0

    pontuacao = {'!', '?', '.'}

    for char in s:
        if char in pontuacao:
            sentence += 1

    return sentence


main()
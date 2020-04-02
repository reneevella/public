#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// double round(double x);
//float roundf(float x);
//long double roundl(long double x);

int count_letters(int n, string s);
int count_words(int n, string s);
int count_sentences(int n, string s);
//double countL(int n, string s);
//double round(double x);

int main (void)
{
    string text = get_string("Insert text: ");
    int sizestr = strlen(text);

    int num_letters = count_letters(sizestr, text);
    int num_words = count_words(sizestr, text);
    int num_sentences = count_sentences(sizestr, text);

    float l = ((float) num_letters / (float) num_words) * 100;
    float s = ((float) num_sentences / (float) num_words) * 100;

    float index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", (int)index);
    }
}


int count_letters(int n, string s)
{
    int letters = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(int n, string s)
{
    int words = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((isblank(s[i]) || s[i] == '\0') && !isblank(s[i-1]) )
        {
            words++;
        }
    }
    return words;
}

int count_sentences(int n, string s)
{
    int sentence = 0;
    for (int i = 0; i < n; i++)
    {
        if ( ( (s[i] == '!') || (s[i] == '?') || (s[i] == '.') ) && !((s[i-1] == '!') || (s[i-1] == '?') || (s[i-1] == '.')))
        {
            sentence++;
        }
    }
    return sentence;
}




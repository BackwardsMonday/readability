#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_leters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:");
    float leters = count_leters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float L = (leters/words)*100;
    float S = (sentences/words)*100;

    int grade = round(0.0588*L-0.296*S-15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_leters(string text)
{
    int letersSize = 0;
    int size = strlen(text);
    for(int i = size; i != -1; i-= 1)
    {
        char letter = text[i];
        if (isalpha(letter))
        {
            letersSize++;
        }
        
    }
    return letersSize;
}

int count_words(string text)
{
    int words = 1;
    int size = strlen(text);
    for(int i = 0; i != size; i+= 1)
    {
        char letter = text[i];
        if (isspace(letter))
        {
            words++;
        }
        
    }
    return words;
}

int count_sentences(string text)
{
    int sententces = 0;
    int size = strlen(text);
    for(int i = 0; i != size; i+= 1)
    {
        int letter = text[i];
        if (letter ==  46|| letter == 33 || letter == 63)
        {
            sententces++;
        }
        
    }
    return sententces;
}
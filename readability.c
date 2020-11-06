#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int index(float L, float S);

float findAverageLetters(int letters, int words);

float findAverageSentences(int sentences, int words);


int main(void)
{   
    string text = get_string("input your text:\n");
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    
    for (int i = 0 ; i < length ; i++)
    {   
    
        
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        if (text[i] == 63 || text[i] == 33 || text[i] == 46)
        {   
            sentences++;
        }
        if (text[i] == 32)
        {
            words++;
        }
        
    }
    
    float L = findAverageLetters(letters, words);
    
    float S = findAverageSentences(sentences, words);
    
    int grade = index(L, S);
    
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
    
    //printf("Letters : %i , Words: %i , Sentences: %i", letters,words,sentences);
    
}

int index(float L, float S)
{
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int index = (int) round(grade);
    return index;
    
}

float findAverageLetters(int letters, int words)
{
    float averageLetters = (float)letters / words * 100;
    return averageLetters;
}

float findAverageSentences(int sentences, int words)
{
    float averageSentences = (float)sentences / words * 100;
    return averageSentences;
}
#include "Header.h"

int findWordPosition(char* str, int wordNumber)
{
    int currentWord = 0;
    bool inWord = false;

    char* p = str;

    while (*p != '\0')
    {
        
        if (*p != ' ' && !inWord)
        {
            inWord = true;
            currentWord++;

            
            if (currentWord == wordNumber)
            {
                return p - str;
            }
        }

        
        if (*p == ' ')
        {
            inWord = false;
        }

        p++;
    }

    return -1;
}
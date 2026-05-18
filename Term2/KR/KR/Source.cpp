#include "Header.h"
#include <cstdio>

int KR::CheckWin(int a, int b, int c)
{
    if (a == b && b == c)
    {
        if (a == 0)
            return 300;

        else if (a == 1)
            return 200;

        else if (a == 2)
            return 100;
    }

    return 0;
}

using namespace System;

void KR::FillIndexes(int* numbers, int size)
{
    Random^ rnd = gcnew Random();

    for (int i = 0; i < size; i++)
    {
        *(numbers + i) = rnd->Next(0, 3);
    }
}

char* KR::CreateMessage(int score)
{
    char* text = new char[50];

    sprintf_s(text, 50, "You have %d points", score);

    return text;
}
#include "Header.h"
#include <cstdio>
#include <fstream>
#include <cstring>

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

void KR::WriteToFile()
{
    FILE* file = fopen("author.txt", "w");

    if (file != NULL)
    {
        fprintf(file,
            "Made by student Kryndach Kateryna,\n"
            "student of group KN-1225a,\n"
            "National Technical University\n"
            "\"Kharkiv Polytechnic Institute\"");

        fclose(file);
    }
}

char* KR::ReadFromFile()
{
    FILE* file = fopen("author.txt", "r");

    char* text = new char[300];

    if (file != NULL)
    {
        char line[100];

        text[0] = '\0';

        while (fgets(line, 100, file))
        {
            strcat(text, line);
        }

        fclose(file);
    }

    return text;
}

void KR::ShowPrizeInfo(
    PrizeInfo* prizes,
    System::Windows::Forms::Label^ l1,
    System::Windows::Forms::Label^ l2,
    System::Windows::Forms::Label^ l3
)
{
    l1->Text =
        gcnew System::String((prizes + 0)->fruit) +
        " x" +
        (prizes + 0)->count.ToString() +
        "  =  " +
        (prizes + 0)->points.ToString() +
        " points";

    l2->Text =
        gcnew System::String((prizes + 1)->fruit) +
        " x" +
        (prizes + 1)->count.ToString() +
        "  =  " +
        (prizes + 1)->points.ToString() +
        " points";

    l3->Text =
        gcnew System::String((prizes + 2)->fruit) +
        " x" +
        (prizes + 2)->count.ToString() +
        "  =  " +
        (prizes + 2)->points.ToString() +
        " points";
}

int KR::AddScore(int totalScore, int score)
{
    if (score == 0)
        return totalScore;

    return AddScore(totalScore + 1, score - 1);
}
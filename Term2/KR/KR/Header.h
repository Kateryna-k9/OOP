#pragma once

namespace KR
{
    int CheckWin(int a, int b, int c);

    struct SpinResult
    {
        int a;
        int b;
        int c;
    };

    int CheckWin(int a, int b, int c);

    void FillIndexes(int* numbers, int size);

    char* CreateMessage(int score);

    void WriteToFile();

    char* ReadFromFile();
    
    struct PrizeInfo
    {
        char fruit[20];
        int count;
        int points;
    };

    void ShowPrizeInfo(
        PrizeInfo* prizes,
        System::Windows::Forms::Label^ l1,
        System::Windows::Forms::Label^ l2,
        System::Windows::Forms::Label^ l3
    );

    int AddScore(int totalScore, int score);
}


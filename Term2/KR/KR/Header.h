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
    
}


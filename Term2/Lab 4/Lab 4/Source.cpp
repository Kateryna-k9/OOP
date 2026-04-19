#include "Header.h"

// Заповнення масиву
void fill(int** mas, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> *(*(mas + i) + j);
        }
    }
}

// Обробка масиву
int* process(int** mas, int N, int M, int* sum, int* size)
{
    *sum = 0;
    *size = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int value = *(*(mas + i) + j);

            if ((value >= 10 && value <= 99) ||
                (value <= -10 && value >= -99))
            {
                (*size)++;
            }
        }
    }

    int* result = new int[*size];

    int k = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int value = *(*(mas + i) + j);

            if ((value >= 10 && value <= 99) ||
                (value <= -10 && value >= -99))
            {
                *(result + k) = value;
                *sum += value;
                k++;
            }
        }
    }

    return result;
}

// Звільнення пам'яті
void free(int** mas, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] * (mas + i);
    }

    delete[] mas;
}
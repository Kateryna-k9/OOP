#pragma once
#include <iostream>
using namespace std;

void fill(int** mas, int N, int M);
int* process(int** mas, int N, int M, int* sum, int* size);
void free(int** mas, int N); 
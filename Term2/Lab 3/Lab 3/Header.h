
#pragma once
#include <string>
#define DEBUG
#define PRINT_TYPE
using namespace std;

struct Component {
    string name;
    char type;
    double value;
    int quantity;
};

const int MAX = 100;


int input(Component arr[]);
int randomFill(Component arr[]);
void sortByName(Component arr[], int n);
void print(Component arr[], int n);
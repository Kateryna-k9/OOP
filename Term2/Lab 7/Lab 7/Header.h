#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>

using namespace std;

struct Component {
    char name[30];
    char type;
    double value;
    int quantity;
};

void input(Component& c);
void randomFill(Component& c);

void writeFromKeyboard();
void writeRandom();

void addToBeginning();
void addToEnd();

void printOne();
void printAll();

void editRecord();

void printComponent(Component c);
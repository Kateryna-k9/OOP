#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Component {
    char name[30];
    char type;
    double value;
    int quantity;
};

void input(Component& c);
void randomFill(Component& c);

void writeFromKeyboard(const char* filename);
void writeRandom(const char* filename);

void addToBeginning(const char* filename);
void addToEnd(const char* filename);

void printOne(const char* filename);
void printAll(const char* filename);

void editRecord(const char* filename);

void printComponent(Component c);
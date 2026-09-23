#pragma once

#include <iostream>

class Component
{
private:
    char designation[20];
    char type;
    double nominal;
    int quantity;

public:
    Component();
    Component(const char* newDesignation, char newType,
        double newNominal, int newQuantity);
    Component(const Component& other);

    char getType() const;
    const char* getDesignation() const;
    double getNominal() const;
    int getQuantity() const;

    void setNominal(double newNominal);
    void setDesignation(const char* newDesignation);
    void setType(char newType);
    void setQuantity(int newQuantity);

    void show() const;

    
    Component& operator=(const Component& other);
    bool operator==(const Component& other) const;
    Component operator+(const Component& other) const;

    
    int operator[](const char* text) const;

    
    void operator()(const char* newDesignation, char newType,
        double newNominal, int newQuantity);

    
    friend bool operator==(const Component& left, const Component& right);
    friend Component operator+(const Component& left, const Component& right);

    
    friend std::ostream& operator<<(std::ostream& out, const Component& component);
    friend std::istream& operator>>(std::istream& in, Component& component);
};
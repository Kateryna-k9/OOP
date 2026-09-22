#include "Figure.h"
#include <iostream>

using namespace std;

Figure::Figure(double radius, double base)
{
    if (base == 0)
    {
        this->radius = radius;
        height = 0;
        this->base = 0;
    }
    else
    {
        this->radius = 0;
        height = radius;
        this->base = base;
    }
}

double Figure::getRadius() const
{
    return radius;
}

double Figure::getHeight() const
{
    return height;
}

double Figure::getBase() const
{
    return base;
}

void Figure::setRadius(double newRadius)
{
    radius = newRadius;
}

void Figure::setHeight(double newHeight)
{
    height = newHeight;
}

void Figure::setBase(double newBase)
{
    base = newBase;
}

double Figure::getCircleArea() const
{
    const double PI = 3.14159;

    return PI * radius * radius;
}

double Figure::getTriangleArea() const
{
    return height * base / 2;
}

void Figure::show() const
{
    if (base == 0)
    {
        cout << "\nCircle" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getCircleArea() << endl;
    }
    else
    {
        cout << "\nTriangle" << endl;
        cout << "Height: " << height << endl;
        cout << "Base: " << base << endl;
        cout << "Area: " << getTriangleArea() << endl;
    }
}
#pragma once

class Figure
{
private:
    double radius;
    double height;
    double base;

public:
    Figure(double radius, double base = 0);

    double getRadius() const;
    double getHeight() const;
    double getBase() const;

    void setRadius(double newRadius);
    void setHeight(double newHeight);
    void setBase(double newBase);

    double getCircleArea() const;
    double getTriangleArea() const;

    void show() const;
};
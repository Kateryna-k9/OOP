
#include "HeaderA.h"



SOBAKA::SOBAKA() : weight(12.5), age(4)
{
    cout << "Constructor SOBAKA" << endl;
}

SOBAKA::~SOBAKA()
{
    cout << "Destructor SOBAKA" << endl;
}

double SOBAKA::getWeight() const
{
    return weight;
}

int SOBAKA::getAge() const
{
    return age;
}

void SOBAKA::setWeight(const double newWeight)
{
    if (newWeight > 0)
    {
        weight = newWeight;
    }
    else
    {
        cout << "Invalid weight!" << endl;
    }
}

void SOBAKA::show() const
{
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Age: " << age << " years" << endl;
}

void SOBAKA::golos() const
{
    if (weight >= 10)
        cout << "WOOF" << endl;
    else
        cout << "woof" << endl;
}


SPANIEL::SPANIEL() : color("Brown")
{
    cout << "Constructor SPANIEL" << endl;
}

SPANIEL::~SPANIEL()
{
    cout << "Destructor SPANIEL" << endl;
}

void SPANIEL::show() const
{
    SOBAKA::show();
    cout << "Color: " << color << endl;
}

void SPANIEL::golos() const
{
    if (getWeight() >= 10)
        cout << "WOOF" << endl;
    else
        cout << "woof" << endl;
}



DOG::DOG() : height(55.0)
{
    cout << "Constructor DOG" << endl;
}

DOG::~DOG()
{
    cout << "Destructor DOG" << endl;
}

void DOG::show() const
{
    SOBAKA::show();
    cout << "Height: " << height << " cm" << endl;
}

void DOG::golos() const
{
    if (getWeight() >= 10)
        cout << "WOOF" << endl;
    else
        cout << "woof" << endl;
}

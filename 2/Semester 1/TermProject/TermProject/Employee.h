
#pragma once
#include "Team.h"

class Employee : public Team
{
private:
    char fullName[100];
    char position[50];
    double salary;

public:
    Employee();

    Employee(const char* name, const char* project,
        const char* leader, const char* fullName,
        const char* position, double salary);

    void setFullName(const char* fullName);
    void setPosition(const char* position);
    void setSalary(double salary);

    const char* getFullName() const;
    const char* getPosition() const;
    double getSalary() const;

    void showInfo() const override;
};


#include "Employee.h"

Employee::Employee() : Team()
{
    setEntityType("Employee");
    setFullName("");
    setPosition("");
    salary = 0;
}

Employee::Employee(const char* name, const char* project,
    const char* leader, const char* fullName,
    const char* position, double salary)
    : Team(name, "Employee", project, leader)
{
    setFullName(fullName);
    setPosition(position);
    setSalary(salary);
}

void Employee::setFullName(const char* fullName)
{
    copyText(this->fullName, fullName, 100);
}

void Employee::setPosition(const char* position)
{
    copyText(this->position, position, 50);
}

void Employee::setSalary(double salary)
{
    if (salary >= 0)
        this->salary = salary;
}

const char* Employee::getFullName() const
{
    return fullName;
}

const char* Employee::getPosition() const
{
    return position;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::showInfo() const
{
    Team::showInfo();

    cout << "Full name: " << fullName << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
}

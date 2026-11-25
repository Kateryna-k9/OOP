
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

Employee::Employee(const Employee& ob) : Team(ob)
{
    setFullName(ob.fullName);
    setPosition(ob.position);
    salary = ob.salary;
}

Employee::~Employee()
{
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

Employee Employee::operator+(double amount) const
{
    Employee temp(*this);

    temp.setSalary(salary + amount);

    return temp;
}


Employee& Employee::operator=(const Employee& ob)
{
    if (this != &ob)
    {
        Team::operator=(ob);

        setFullName(ob.fullName);
        setPosition(ob.position);
        salary = ob.salary;
    }

    return *this;
}

Employee& Employee::operator++()
{
    salary += 1000;
    return *this;
}
Employee Employee::operator--(int)
{
    Employee temp(*this);

    if (salary >= 1000)
        salary -= 1000;
    else
        salary = 0;

    return temp;
}


bool Employee::operator==(const Employee& ob) const
{
    return salary == ob.salary;
}


bool Employee::operator!=(const Employee& ob) const
{
    return !(*this == ob);
}


bool Employee::operator>(const Employee& ob) const
{
    return salary > ob.salary;
}


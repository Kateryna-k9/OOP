
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


double salaryDifference(const Employee& emp1, const Employee& emp2)
{
    return emp1.salary - emp2.salary;
}

Employee operator+(double amount, const Employee& emp)
{
    Employee temp(emp);

    temp.setSalary(emp.salary + amount);

    return temp;
}

ostream& operator<<(ostream& out, const Employee& emp)
{
    out << "Team: " << emp.getName() << endl;
    out << "Entity type: " << emp.getEntityType() << endl;
    out << "Project: " << emp.getProject() << endl;
    out << "Leader: " << emp.getLeader() << endl;
    out << "Full name: " << emp.fullName << endl;
    out << "Position: " << emp.position << endl;
    out << "Salary: " << emp.salary << endl;

    return out;
}

istream& operator>>(istream& in, Employee& emp)
{
    char teamName[50];
    char project[50];
    char leader[50];
    char fullName[100];
    char position[50];
    double salary;

    in >> ws;

    if (!in.getline(teamName, 50) ||
        !in.getline(project, 50) ||
        !in.getline(leader, 50) ||
        !in.getline(fullName, 100) ||
        !in.getline(position, 50) ||
        !(in >> salary))
    {
        return in;
    }

    if (salary < 0)
    {
        in.setstate(ios::failbit);
        return in;
    }

    emp.setName(teamName);
    emp.setEntityType("Employee");
    emp.setProject(project);
    emp.setLeader(leader);
    emp.setFullName(fullName);
    emp.setPosition(position);
    emp.setSalary(salary);

    return in;
}

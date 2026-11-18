
#include "Expert.h"

Expert::Expert() : Team()
{
    setEntityType("Expert");
    setFullName("");
    setSpecialization("");
    setFunctions("");
}

Expert::Expert(const char* name, const char* project,
    const char* leader, const char* fullName,
    const char* specialization, const char* functions)
    : Team(name, "Expert", project, leader)
{
    setFullName(fullName);
    setSpecialization(specialization);
    setFunctions(functions);
}

void Expert::setFullName(const char* fullName)
{
    copyText(this->fullName, fullName, 100);
}

void Expert::setSpecialization(const char* specialization)
{
    copyText(this->specialization, specialization, 100);
}

void Expert::setFunctions(const char* functions)
{
    copyText(this->functions, functions, 150);
}

const char* Expert::getFullName() const
{
    return fullName;
}

const char* Expert::getSpecialization() const
{
    return specialization;
}

const char* Expert::getFunctions() const
{
    return functions;
}

bool Expert::hasSpecialization(const char* required) const
{
    if (required == nullptr)
        return false;

    int i = 0;

    while (*(specialization + i) != '\0' &&
        *(required + i) != '\0')
    {
        if (*(specialization + i) != *(required + i))
            return false;

        i++;
    }

    return *(specialization + i) == '\0' &&
        *(required + i) == '\0';
}

void Expert::showInfo() const
{
    Team::showInfo();

    cout << "Full name: " << fullName << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Functions: " << functions << endl;
}

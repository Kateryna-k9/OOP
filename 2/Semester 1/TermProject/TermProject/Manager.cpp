
#include "Manager.h"

Manager::Manager() : Team()
{
    setEntityType("Manager");
    setFullName("");
    setSkills("");
    setWorkStatus("");
}

Manager::Manager(const char* name, const char* project,
    const char* leader, const char* fullName,
    const char* skills, const char* workStatus)
    : Team(name, "Manager", project, leader)
{
    setFullName(fullName);
    setSkills(skills);
    setWorkStatus(workStatus);
}

void Manager::setFullName(const char* fullName)
{
    copyText(this->fullName, fullName, 100);
}

void Manager::setSkills(const char* skills)
{
    copyText(this->skills, skills, 150);
}

void Manager::setWorkStatus(const char* workStatus)
{
    copyText(this->workStatus, workStatus, 30);
}

const char* Manager::getFullName() const
{
    return fullName;
}

const char* Manager::getSkills() const
{
    return skills;
}

const char* Manager::getWorkStatus() const
{
    return workStatus;
}

bool Manager::isActive() const
{
    const char* active = "Active";
    int i = 0;

    while (*(workStatus + i) != '\0' &&
        *(active + i) != '\0')
    {
        if (*(workStatus + i) != *(active + i))
            return false;

        i++;
    }

    return *(workStatus + i) == '\0' &&
        *(active + i) == '\0';
}

void Manager::showInfo() const
{
    Team::showInfo();

    cout << "Full name: " << fullName << endl;
    cout << "Skills: " << skills << endl;
    cout << "Work status: " << workStatus << endl;
}

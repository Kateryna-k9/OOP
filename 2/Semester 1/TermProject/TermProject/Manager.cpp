
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

Manager::Manager(const Manager& ob) : Team(ob)
{
    setFullName(ob.fullName);
    setSkills(ob.skills);
    setWorkStatus(ob.workStatus);
}

Manager::~Manager()
{
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

Manager& Manager::operator=(const Manager& ob)
{
    if (this != &ob)
    {
        Team::operator=(ob);

        setFullName(ob.fullName);
        setSkills(ob.skills);
        setWorkStatus(ob.workStatus);
    }

    return *this;
}

bool Manager::operator==(const Manager& ob) const
{
    int i = 0;

    while (*(workStatus + i) != '\0' &&
        *(ob.workStatus + i) != '\0')
    {
        if (*(workStatus + i) != *(ob.workStatus + i))
            return false;

        i++;
    }

    return *(workStatus + i) == '\0' &&
        *(ob.workStatus + i) == '\0';
}

bool Manager::operator!() const
{
    return !isActive();
}

ostream& operator<<(ostream& out, const Manager& manager)
{
    out << "Team: " << manager.getName() << endl;
    out << "Entity type: " << manager.getEntityType() << endl;
    out << "Project: " << manager.getProject() << endl;
    out << "Leader: " << manager.getLeader() << endl;
    out << "Full name: " << manager.fullName << endl;
    out << "Skills: " << manager.skills << endl;
    out << "Work status: " << manager.workStatus << endl;

    return out;
}

istream& operator>>(istream& in, Manager& manager)
{
    char teamName[50];
    char project[50];
    char leader[50];
    char fullName[100];
    char skills[150];
    char workStatus[30];

    in >> ws;

    if (!in.getline(teamName, 50) ||
        !in.getline(project, 50) ||
        !in.getline(leader, 50) ||
        !in.getline(fullName, 100) ||
        !in.getline(skills, 150) ||
        !in.getline(workStatus, 30))
    {
        return in;
    }

    manager.setName(teamName);
    manager.setEntityType("Manager");
    manager.setProject(project);
    manager.setLeader(leader);
    manager.setFullName(fullName);
    manager.setSkills(skills);
    manager.setWorkStatus(workStatus);

    return in;
}

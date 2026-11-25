
#include "Team.h"

void Team::copyText(char* destination, const char* source, int maxSize)
{
    int i = 0;

    if (source != nullptr)
    {
        while (i < maxSize - 1 && *(source + i) != '\0')
        {
            *(destination + i) = *(source + i);
            i++;
        }
    }

    *(destination + i) = '\0';
}


Team::Team()
{
    setName("");
    setEntityType("");
    setProject("");
    setLeader("");
}


Team::Team(const char* name, const char* entityType,
    const char* project, const char* leader)
{
    setName(name);
    setEntityType(entityType);
    setProject(project);
    setLeader(leader);
}


Team::Team(const Team& ob)
{
    setName(ob.name);
    setEntityType(ob.entityType);
    setProject(ob.project);
    setLeader(ob.leader);
}


Team::~Team()
{
}

void Team::setName(const char* name)
{
    copyText(this->name, name, 50);
}

void Team::setEntityType(const char* entityType)
{
    copyText(this->entityType, entityType, 30);
}

void Team::setProject(const char* project)
{
    copyText(this->project, project, 50);
}

void Team::setLeader(const char* leader)
{
    copyText(this->leader, leader, 50);
}

const char* Team::getName() const
{
    return name;
}

const char* Team::getEntityType() const
{
    return entityType;
}

const char* Team::getProject() const
{
    return project;
}

const char* Team::getLeader() const
{
    return leader;
}

void Team::showInfo() const
{
    cout << "Team: " << name << endl;
    cout << "Entity type: " << entityType << endl;
    cout << "Project: " << project << endl;
    cout << "Leader: " << leader << endl;
}


Team& Team::operator=(const Team& ob)
{
    if (this != &ob)
    {
        setName(ob.name);
        setEntityType(ob.entityType);
        setProject(ob.project);
        setLeader(ob.leader);
    }

    return *this;
}


bool Team::operator==(const Team& ob) const
{
    int i = 0;

    while (*(name + i) != '\0' &&
        *(ob.name + i) != '\0')
    {
        if (*(name + i) != *(ob.name + i))
            return false;

        i++;
    }

    return *(name + i) == '\0' &&
        *(ob.name + i) == '\0';
}


bool Team::operator!=(const Team& ob) const
{
    return !(*this == ob);
}

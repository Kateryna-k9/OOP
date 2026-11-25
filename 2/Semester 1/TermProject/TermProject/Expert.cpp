
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

Expert::Expert(const Expert& ob) : Team(ob)
{
    setFullName(ob.fullName);
    setSpecialization(ob.specialization);
    setFunctions(ob.functions);
}

Expert::~Expert()
{
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


Expert& Expert::operator=(const Expert& ob)
{
    if (this != &ob)
    {
        Team::operator=(ob);

        setFullName(ob.fullName);
        setSpecialization(ob.specialization);
        setFunctions(ob.functions);
    }

    return *this;
}


bool Expert::operator==(const Expert& ob) const
{
    int i = 0;

    while (*(specialization + i) != '\0' &&
        *(ob.specialization + i) != '\0')
    {
        if (*(specialization + i) != *(ob.specialization + i))
            return false;

        i++;
    }

    return *(specialization + i) == '\0' &&
        *(ob.specialization + i) == '\0';
}


bool Expert::operator()(const char* required) const
{
    return hasSpecialization(required);
}

ostream& operator<<(ostream& out, const Expert& expert)
{
    out << "Team: " << expert.getName() << endl;
    out << "Entity type: " << expert.getEntityType() << endl;
    out << "Project: " << expert.getProject() << endl;
    out << "Leader: " << expert.getLeader() << endl;
    out << "Full name: " << expert.fullName << endl;
    out << "Specialization: " << expert.specialization << endl;
    out << "Functions: " << expert.functions << endl;

    return out;
}

istream& operator>>(istream& in, Expert& expert)
{
    char teamName[50];
    char project[50];
    char leader[50];
    char fullName[100];
    char specialization[100];
    char functions[150];

    in >> ws;

    if (!in.getline(teamName, 50) ||
        !in.getline(project, 50) ||
        !in.getline(leader, 50) ||
        !in.getline(fullName, 100) ||
        !in.getline(specialization, 100) ||
        !in.getline(functions, 150))
    {
        return in;
    }

    expert.setName(teamName);
    expert.setEntityType("Expert");
    expert.setProject(project);
    expert.setLeader(leader);
    expert.setFullName(fullName);
    expert.setSpecialization(specialization);
    expert.setFunctions(functions);

    return in;
}

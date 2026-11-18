
#pragma once
#include <iostream>

using namespace std;

class Team
{
protected:
    char name[50];
    char entityType[30];
    char project[50];
    char leader[50];

    void copyText(char* destination, const char* source, int maxSize);

public:
    Team();
    Team(const char* name, const char* entityType,
        const char* project, const char* leader);

    virtual ~Team() = default;

    void setName(const char* name);
    void setEntityType(const char* entityType);
    void setProject(const char* project);
    void setLeader(const char* leader);

    const char* getName() const;
    const char* getEntityType() const;
    const char* getProject() const;
    const char* getLeader() const;

    virtual void showInfo() const;
};

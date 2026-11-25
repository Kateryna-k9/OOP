
#pragma once
#include "Team.h"

class Manager : public Team
{
private:
    char fullName[100];
    char skills[150];
    char workStatus[30];

public:
    Manager();

    Manager(const char* name, const char* project,
        const char* leader, const char* fullName,
        const char* skills, const char* workStatus);

    Manager(const Manager& ob);

    ~Manager() override;

    Manager& operator=(const Manager& ob);

    bool operator==(const Manager& ob) const;
    bool operator!() const;


    void setFullName(const char* fullName);
    void setSkills(const char* skills);
    void setWorkStatus(const char* workStatus);

    const char* getFullName() const;
    const char* getSkills() const;
    const char* getWorkStatus() const;

    bool isActive() const;

    void showInfo() const override;
};

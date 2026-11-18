
#pragma once
#include "Team.h"

class Expert : public Team
{
private:
    char fullName[100];
    char specialization[100];
    char functions[150];

public:
    Expert();

    Expert(const char* name, const char* project,
        const char* leader, const char* fullName,
        const char* specialization, const char* functions);

    void setFullName(const char* fullName);
    void setSpecialization(const char* specialization);
    void setFunctions(const char* functions);

    const char* getFullName() const;
    const char* getSpecialization() const;
    const char* getFunctions() const;

    bool hasSpecialization(const char* required) const;

    void showInfo() const override;
};

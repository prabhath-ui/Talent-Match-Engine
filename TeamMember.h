// TeamMember.h
#ifndef TEAM_MEMBER_H
#define TEAM_MEMBER_H

#include <string>
#include "ProjectCategory.h"
class TeamMember {
protected:
    std::string id;
    std::string name;
    double baseScore;
    int yearsOfExperience;
    int projectsCompleted;

public:
    TeamMember(std::string id, std::string name, double baseScore, int exp, int projects);
    virtual ~TeamMember() = default; 

    // Declarations only!
    int getYearsOfExperience() const;
    int getProjectsCompleted() const;
    virtual double calculateProjectSuitability(ProjectCategory category) = 0;

    double calculateExperienceBonus() const;
    std::string getId() const;
};

#endif
#include "TeamMember.h"

TeamMember::TeamMember(std::string id, std::string name, double baseScore, int exp, int projects)
    : id(id), name(name), baseScore(baseScore), yearsOfExperience(exp), projectsCompleted(projects) {}

int TeamMember::getYearsOfExperience() const {
    return yearsOfExperience;
}

int TeamMember::getProjectsCompleted() const {
    return projectsCompleted;
}
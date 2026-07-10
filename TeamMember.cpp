#include "TeamMember.h"
#include <stdexcept> 

TeamMember::TeamMember(std::string id, std::string name, double baseScore, int exp, int projects)
    : id(id), name(name) { 
    
    if (baseScore < 0.0 || baseScore > 100.0) {
        throw std::invalid_argument("Base score must be between 0.0 and 100.0");
    }
    
    if (exp < 0 || projects < 0) {
        throw std::invalid_argument("Experience and projects completed cannot be negative");
    }

    this->baseScore = baseScore;
    this->yearsOfExperience = exp;
    this->projectsCompleted = projects;
}

// Ensure these getters are explicitly defined here:
int TeamMember::getYearsOfExperience() const { 
    return yearsOfExperience; 
}

int TeamMember::getProjectsCompleted() const { 
    return projectsCompleted; 
}

double TeamMember::calculateExperienceBonus() const {
    double bonus = 0.0;
    if (yearsOfExperience > 5) {
        bonus += 15.0;
    } else if (projectsCompleted >= 8) {
        bonus += 5.0;
    } else {
        bonus -= 10.0;
    }
    return bonus;
}
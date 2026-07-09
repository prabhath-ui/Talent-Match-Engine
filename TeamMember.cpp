#include "TeamMember.h"

TeamMember::TeamMember(std::string id, std::string name, double baseScore, int exp, int projects)
    : id(id), name(name), baseScore(baseScore), yearsOfExperience(exp), projectsCompleted(projects) {}

// Added TeamMember:: scope here
double TeamMember::calculateExperienceBonus() const {
    double bonus = 0.0;
    
    // Look at member variables directly! No "member->" needed
    if (yearsOfExperience > 5) {
        bonus += 15.0;
    } else if (projectsCompleted >= 8) {
        bonus += 5.0;
    } else {
        bonus -= 10.0;
    }

    return bonus;
}
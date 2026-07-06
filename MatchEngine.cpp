#include "MatchEngine.h"

double MatchEngine::calculateMatchScore(TeamMember* member, std::string projectType) {
    // 1. Polymorphic call: The member class handles its own logic!
    double score = member->calculateProjectSuitability(projectType);

    // 2. Adjustments
    if (member->getYearsOfExperience() > 5) score += 15.0;
    else if (member->getProjectsCompleted() >= 8) score += 5.0;
    else score -= 10.0;

    // 3. Clamp
    if (score > 100.0) score = 100.0;
    if (score < 0.0) score = 0.0;

    return score;
}
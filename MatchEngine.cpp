#include "MatchEngine.h"

double MatchEngine::calculateMatchScore(const std::unique_ptr<TeamMember>& member, std::string projectType) {
    if (!member) return 0.0; // Fail-safe null check!

    // The -> operator works exactly the same with smart pointers!
    double score = member->calculateProjectSuitability(projectType);

    if (member->getYearsOfExperience() > 5) score += 15.0;
    else if (member->getProjectsCompleted() >= 8) score += 5.0;
    else score -= 10.0;

    if (score > 100.0) score = 100.0;
    if (score < 0.0) score = 0.0;

    return score;
}
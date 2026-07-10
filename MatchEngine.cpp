#include "MatchEngine.h"

double MatchEngine::calculateMatchScore(const std::unique_ptr<TeamMember>& member, const Project& project) {
    if (!member) return 0.0;

    
    double score = member->calculateProjectSuitability(project.getCategory());

    if (member->getYearsOfExperience() > 5) score += 15.0;
    else if (member->getProjectsCompleted() >= 8) score += 5.0;
    else score -= 10.0;

    if (score > 100.0) score = 100.0;
    if (score < 0.0) score = 0.0;

    return score;
}
#include "MatchEngine.h"

double MatchEngine::calculateMatchScore(const std::unique_ptr<TeamMember>& member, const Project& project) {
    if (!member) return 0.0;

    
    double score = member->calculateProjectSuitability(project.getCategory());

    score+=member->calculateExperienceBonus();

    if (score > 100.0) score = 100.0;
    if (score < 0.0) score = 0.0;

    return score;
}
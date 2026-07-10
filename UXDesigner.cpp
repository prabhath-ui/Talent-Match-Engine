#include "UXDesigner.h"
#include <algorithm> // Crucial for std::find to work!

UXDesigner::UXDesigner(std::string id, std::string name, double baseScore, 
                       int exp, int projects, std::unordered_set<std::string> designerTools)
    : TeamMember(id, name, baseScore, exp, projects), tools(designerTools) {}

double UXDesigner::calculateProjectSuitability(ProjectCategory category) {
    double score = 70.0;
    
    if (category == ProjectCategory::Web) {
        bool hasFigma = (tools.find("Figma") != tools.end());
        if (hasFigma) score += 15.0; 
        else score -= 30.0; 
    } 
    else if (category == ProjectCategory::Research) {
        bool hasInterviews = (tools.find("User Interviewing") != tools.end());
        bool hasABTesting = (tools.find("A/B Testing") != tools.end());
        
        if (hasInterviews || hasABTesting) score += 20.0;
        else score -= 35.0;
    }

    return score;
}
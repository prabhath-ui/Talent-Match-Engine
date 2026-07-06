#include "UXDesigner.h"
#include <algorithm> // Crucial for std::find to work!

UXDesigner::UXDesigner(std::string id, std::string name, double baseScore, 
                       int exp, int projects, std::vector<std::string> designerTools)
    : TeamMember(id, name, baseScore, exp, projects), tools(designerTools) {}

double UXDesigner::calculateProjectSuitability(std::string projectType) {
    double score = 70.0;
    
    if (projectType == "Web") {
        bool hasFigma = (std::find(tools.begin(), tools.end(), "Figma") != tools.end());
        
        if (hasFigma) {
            score += 15.0; 
        } else {
            score -= 30.0; 
        }
    } 
    else if (projectType == "Research") {
        bool hasInterviews = (std::find(tools.begin(), tools.end(), "User Interviewing") != tools.end());
        bool hasABTesting = (std::find(tools.begin(), tools.end(), "A/B Testing") != tools.end());
        
        if (hasInterviews || hasABTesting) {
            score += 20.0;
        } else {
            score -= 35.0;
        }
    }

    return score;
}
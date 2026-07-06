#include "SoftwareEngineer.h"
#include <algorithm> // Crucial for std::find to work!

SoftwareEngineer::SoftwareEngineer(std::string id, std::string name, double baseScore, 
                                   int exp, int projects, std::vector<std::string> langs, bool fullStack)
    : TeamMember(id, name, baseScore, exp, projects), languages(langs), isFullStack(fullStack) {}

double SoftwareEngineer::calculateProjectSuitability(std::string projectType) { 
    double score = 70.0;
    
    if (this->isFullStack) {
        score += 10.0;
    } else {
        score -= 10.0;
    }
    
    if (projectType == "Cloud") {
        bool hasPython = (std::find(languages.begin(), languages.end(), "Python") != languages.end());
        bool hasGo = (std::find(languages.begin(), languages.end(), "Go") != languages.end());
        
        if (hasPython || hasGo) {
            score += 15.0;
        } else {
            score -= 20.0;
        }
    }
    
    return score;
}
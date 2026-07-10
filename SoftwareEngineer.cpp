#include "SoftwareEngineer.h"
#include <algorithm> 

SoftwareEngineer::SoftwareEngineer(std::string id, std::string name, double baseScore, 
                                   int exp, int projects,std::unordered_set<std::string> langs, bool fullStack)
    : TeamMember(id, name, baseScore, exp, projects), languages(langs), isFullStack(fullStack) {}


double SoftwareEngineer::calculateProjectSuitability(ProjectCategory category) { 
    double score = 70.0;
    
    if (this->isFullStack) score += 10.0;
    else score -= 10.0;
    
    
    if (category == ProjectCategory::Cloud) {
        bool hasPython = (languages.find("Python") != languages.end());
        bool hasGo = (languages.find("Go") != languages.end());
        
        if (hasPython || hasGo) score += 15.0;
        else score -= 20.0;
    }
    
    return score;
}
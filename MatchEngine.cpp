#include <iostream>
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include <algorithm>

using namespace std;

double MatchEngine::calculateMatchScore(TeamMember* member, string projectType) {
    double score = 60.0;

    // Fixed to match TeamMember.h getter names precisely
    if (member->getYearsOfExperience() > 5) {
        score += 15.0;
    } 
    else if (member->getProjectsCompleted() >= 8) {
        score += 5.0;
    } 
    else {
        score -= 10.0;
    }

    SoftwareEngineer* eng = dynamic_cast<SoftwareEngineer*>(member);
    UXDesigner* designer = dynamic_cast<UXDesigner*>(member);

    if (eng != nullptr) {
        auto langs = eng->getLanguages();
        
        if (projectType == "Enterprise") {
            if (find(langs.begin(), langs.end(), "Java") != langs.end() ||
                find(langs.begin(), langs.end(), "C++") != langs.end()) {
                score += 25.0;
            } else {
                score -= 20.0;
            }
        } 
        else if (projectType == "Mobile") {
            if (find(langs.begin(), langs.end(), "Kotlin") != langs.end() ||
                find(langs.begin(), langs.end(), "Swift") != langs.end()) {
                score += 25.0;
            } else {
                score -= 20.0;
            }
        }
    } 
    else if (designer != nullptr) {
        auto tools = designer->getTools();
        
        if (projectType == "Enterprise") {
            if (find(tools.begin(), tools.end(), "Figma") != tools.end()) {
                score += 25.0;
            } else {
                score -= 20.0;
            }
        } 
        else if (projectType == "Mobile") {
            if (find(tools.begin(), tools.end(), "Adobe XD") != tools.end()) {
                score += 25.0;
            } else {
                score -= 20.0;
            }
        }
    }

    if (score > 100.0) score = 100.0;
    if (score < 0.0) score = 0.0;

    return score;
}
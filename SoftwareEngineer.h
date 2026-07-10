
#ifndef SOFTWARE_ENGINEER_H
#define SOFTWARE_ENGINEER_H

#include "TeamMember.h"
#include <unordered_set>
#include <string>
#include "ProjectCategory.h"

class SoftwareEngineer : public TeamMember {
private:
    std::unordered_set<std::string> languages;
    bool isFullStack;

public:
    SoftwareEngineer(std::string id, std::string name, double baseScore, 
                     int exp, int projects, std::unordered_set<std::string> langs, bool fullStack);

    // This is just a declaration. No logic, no body, just a semicolon!
    double calculateProjectSuitability(ProjectCategory category) override;
};

#endif
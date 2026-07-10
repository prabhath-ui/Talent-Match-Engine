#ifndef UX_DESIGNER_H
#define UX_DESIGNER_H

#include "TeamMember.h"
#include <unordered_set>
#include <string>
#include "ProjectCategory.h"

class UXDesigner : public TeamMember {
private:
    std::unordered_set<std::string> tools;

public:
    UXDesigner(std::string id, std::string name, double baseScore, 
               int exp, int projects, std::unordered_set<std::string> designerTools);

    // This is just a declaration. No logic, no body, just a semicolon!
    double calculateProjectSuitability(ProjectCategory category) override;
};

#endif
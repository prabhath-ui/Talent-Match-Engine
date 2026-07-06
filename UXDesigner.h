#ifndef UX_DESIGNER_H
#define UX_DESIGNER_H

#include "TeamMember.h"
#include <vector>
#include <string>

class UXDesigner : public TeamMember {
private:
    std::vector<std::string> tools;

public:
    UXDesigner(std::string id, std::string name, double baseScore, 
               int exp, int projects, std::vector<std::string> designerTools);

    // This is just a declaration. No logic, no body, just a semicolon!
    double calculateProjectSuitability(std::string projectType) override;
};

#endif
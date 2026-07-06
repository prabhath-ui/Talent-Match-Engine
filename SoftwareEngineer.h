
#ifndef SOFTWARE_ENGINEER_H
#define SOFTWARE_ENGINEER_H

#include "TeamMember.h"
#include <vector>
#include <string>

class SoftwareEngineer : public TeamMember {
private:
    std::vector<std::string> languages;
    bool isFullStack;

public:
    SoftwareEngineer(std::string id, std::string name, double baseScore, 
                     int exp, int projects, std::vector<std::string> langs, bool fullStack);

    // This is just a declaration. No logic, no body, just a semicolon!
    double calculateProjectSuitability(std::string projectType) override;
};

#endif
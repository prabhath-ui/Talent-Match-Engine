
#include <vector>

#ifndef SOFTWAREENGINEER_H
#define SOFTWAREENGINEER_H

#include <string>
#include <vector>
#include "TeamMember.h"

class SoftwareEngineer : public TeamMember {
private:
    std::vector<std::string> languages; // Changed from std::string to a vector
    bool isFullStack;

public:
    SoftwareEngineer(std::string id, std::string name, double rate, int exp, int projects, 
                     std::vector<std::string> langs, bool fullStack)
        : TeamMember(id, name, rate, exp, projects), languages(langs), isFullStack(fullStack) {}

    std::vector<std::string> getLanguages() const { return languages; }
    bool getIsFullStack() const { return isFullStack; }
};

#endif
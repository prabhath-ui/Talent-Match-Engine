#ifndef UXDESIGNER_H
#define UXDESIGNER_H

#include <string>
#include <vector> // Add this!
#include "TeamMember.h"

class UXDesigner : public TeamMember {
private:
    std::vector<std::string> tools; // Changed from std::string to a vector
    bool hasPortfolio;

public:
    UXDesigner(std::string id, std::string name, double rate, int exp, int projects, 
               std::vector<std::string> tls, bool portfolio)
        : TeamMember(id, name, rate, exp, projects), tools(tls), hasPortfolio(portfolio) {}

    std::vector<std::string> getTools() const { return tools; }
    bool getHasPortfolio() const { return hasPortfolio; }
};

#endif
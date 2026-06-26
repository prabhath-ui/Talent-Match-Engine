#ifndef UXDESIGNER_H
#define UXDESIGNER_H

#include <string>
#include "TeamMember.h"

class UXDesigner : public TeamMember{
    public:
      UXDesigner(std::string id, std::string name, double rate, int exp, int projects,std::string DesignTool,bool Portfolio)
        : TeamMember(id, name, rate, exp, projects),mainDesignTool(DesignTool),hasPortfolio(Portfolio) {}

        double calculateProjectSuitability(std::string projectType) override { return 0.0; }
    private :
       std:: string mainDesignTool;
       bool hasPortfolio;
};

#endif
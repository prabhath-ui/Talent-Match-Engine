#ifndef SOFTWAREENGINEER_H
#define SOFTWAREENGINEER_H

#include <string>
#include "TeamMember.h"

class SoftwareEngineer : public TeamMember {
  public:
    // SoftwareEngineer Constructor
    SoftwareEngineer(std::string id, std::string name, double rate, int exp, int projects, std::string lang, bool fullStack)
        : TeamMember(id, name, rate, exp, projects), programmingLanguage(lang), isFullStack(fullStack) {}

    double calculateProjectSuitability(std::string projectType) override { return 0.0; }
    
    private:
      std::string programmingLanguage;
      bool isFullStack;
};

#endif
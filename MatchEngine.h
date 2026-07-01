#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include <string>
#include "TeamMember.h"

class MatchEngine {
public: 
    // Just a declaration blueprint ending with a semicolon!
    static double calculateMatchScore(TeamMember* member, std::string projectType);
};

#endif
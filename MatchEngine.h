#include <memory>
#include <string>
#include "TeamMember.h"
#include "Project.h"

class MatchEngine {
public:
    // Update raw pointer to a const reference of a unique_ptr
    static double calculateMatchScore(const std::unique_ptr<TeamMember>& member, const Project& project);
};
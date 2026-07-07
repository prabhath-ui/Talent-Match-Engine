#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include "ProjectCategory.h"

class Project {
private:
    std::string projectId;
    ProjectCategory category;
    std::vector<std::string> requiredTech;

public:
    Project(std::string id, ProjectCategory cat, std::vector<std::string> tech)
        : projectId(id), category(cat), requiredTech(tech) {}

    ProjectCategory getCategory() const { return category; }
    const std::vector<std::string>& getRequiredTech() const { return requiredTech; }
};

#endif
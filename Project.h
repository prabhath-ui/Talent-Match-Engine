#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <stdexcept> // Required for std::invalid_argument
#include "ProjectCategory.h"

class Project {
private:
    std::string id;
    ProjectCategory category;
    std::vector<std::string> requiredSkills;

public:
    // Inline constructor with safety check
    Project(std::string id, ProjectCategory category, std::vector<std::string> reqSkills)
        : category(category), requiredSkills(reqSkills) {
        
        // Safety guard: Don't allow empty project IDs
        if (id.empty()) {
            throw std::invalid_argument("Project ID cannot be empty");
        }
        
        this->id = id;
    }

    std::string getId() const { return id; }
    ProjectCategory getCategory() const { return category; }
    const std::vector<std::string>& getRequiredSkills() const { return requiredSkills; }
};

#endif
// TeamMember.h
#ifndef TEAMMEMBER_H
#define TEAMMEMBER_H

#include <string>

class TeamMember {
protected:
    // Core Identity Attributes
    std::string employeeID;
    std::string fullName;
    double hourlyRate;
    bool isAvailable;

    // Track Record Attributess
    int yearsOfExperience;
    int projectsCompleted;

public:
    //Constructor
    TeamMember(std::string id, std::string name, double rate, int exp, int projects)
         : employeeID(id),
      fullName(name),
      hourlyRate(rate),
      isAvailable(true),
      yearsOfExperience(exp),
      projectsCompleted(projects)
{
}
    // Virtual Destructor: Crucial for C++ OOP memory safety

    virtual ~TeamMember() = default; 

    //Get methods
    std::string getEmployeeID() const { return employeeID; }
    std::string getFullName() const { return fullName; }
    double getHourlyRate() const { return hourlyRate; }
    bool getIsAvailable() const { return isAvailable; }
    int getYearsOfExperience() const { return yearsOfExperience; }
    int getProjectsCompleted() const { return projectsCompleted; }

    //Set methods
    void setHourlyRate(double rate) { hourlyRate = rate; }

    void updateAvailability(bool Available){
        this->isAvailable=Available;
    }
    virtual double calculateProjectSuitability(std::string projectType) = 0;
};

#endif // TEAMMEMBER_H
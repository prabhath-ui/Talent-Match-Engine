#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept> 
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "Project.h"
#include <fstream>

using namespace std;

int main() {
    try {
        vector<unique_ptr<TeamMember>> talentRegistry;

        talentRegistry.push_back(make_unique<SoftwareEngineer>(
            "SE-02", "Charlie Cloud", 90.0, 6, 12, 
            std::unordered_set<string>{"Go", "Docker"}, 
            true
        ));

        Project cloudDeployment("PRJ-99", ProjectCategory::Cloud, {"Go", "Kubernetes"});

    
        ofstream reportFile("match_report.txt");
        if (!reportFile.is_open()) {
            throw runtime_error("Failed to open or create match_report.txt");
        }

        
        for (const auto& member : talentRegistry) {
            double score = MatchEngine::calculateMatchScore(member, cloudDeployment);
            
            
            cout << "Profile Evaluation Match: " << score << "%" << endl;
        
            reportFile << "Candidate ID: " << member->getId() << "\n";
            reportFile << "Profile Evaluation Match: " << score << "%\n";
            reportFile << "----------------------------------------\n";
        }

        reportFile.close();
        cout << "\n[Success] Report successfully exported to match_report.txt!" << endl;

    } 
    catch (const std::invalid_argument& e) {
        cerr << "Configuration Error: " << e.what() << endl;
        return 1; 
    }
    catch (const std::exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept> 
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "Project.h"

using namespace std;

int main() {
    try {
        // The try block watches this code for any thrown exceptions
        vector<unique_ptr<TeamMember>> talentRegistry;

        talentRegistry.push_back(make_unique<SoftwareEngineer>(
            "SE-02", "Charlie Cloud", 90.0, 6, 12, 
            std::unordered_set<string>{"Go", "Docker"}, 
            true
        ));

        Project cloudDeployment("PRJ-99", ProjectCategory::Cloud, {"Go", "Kubernetes"});

        for (const auto& member : talentRegistry) {
            double score = MatchEngine::calculateMatchScore(member, cloudDeployment);
            cout << "Profile Evaluation Match: " << score << "%" << endl;
        }
    } 
    catch (const std::invalid_argument& e) {
        // If an invalid_argument happens, this code runs instead of crashing!
        cerr << "Configuration Error: " << e.what() << endl;
        return 1; 
    }
    catch (const std::exception& e) {
        // Catch-all for any other unexpected standard exception
        cerr << "An unexpected error occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}
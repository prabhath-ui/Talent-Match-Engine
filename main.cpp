#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set> // <-- Added this include!
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "Project.h"

using namespace std;

int main() {
    vector<unique_ptr<TeamMember>> talentRegistry;

    talentRegistry.push_back(make_unique<SoftwareEngineer>(
        "SE-02", "Charlie Cloud", 90.0, 6, 12, 
        std::unordered_set<string>{"Go", "Docker"}, // <-- Changed vector to unordered_set here
        true
    ));

    Project cloudDeployment("PRJ-99", ProjectCategory::Cloud, {"Go", "Kubernetes"});

    for (const auto& member : talentRegistry) {
        // Pass the project object directly!
        double score = MatchEngine::calculateMatchScore(member, cloudDeployment);
        cout << "Profile Evaluation Match: " << score << "%" << endl;
    }

    return 0;
}
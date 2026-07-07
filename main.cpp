#include <iostream>
#include <vector>
#include <memory> // Required for std::unique_ptr and std::make_unique
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"

using namespace std;

int main() {
    // Create a heterogeneous registry container managing diverse roles polymorphically
    vector<unique_ptr<TeamMember>> talentRegistry;

    // 1. Populate registry using modern heap allocation
    talentRegistry.push_back(make_unique<SoftwareEngineer>(
        "SE-02", "Charlie Cloud", 90.0, 6, 12, vector<string>{"Go", "Docker"}, true
    ));

    talentRegistry.push_back(make_unique<UXDesigner>(
        "UX-01", "Dani Draft", 85.0, 2, 9, vector<string>{"Sketch", "Photoshop"}
    ));

    // 2. Process our engine scores cleanly by looping through the registry
    cout << "=== Day 14 Talent Engine Registry Evaluation ===" << endl;
    for (const auto& member : talentRegistry) {
        // Evaluate every member against a "Cloud" project footprint
        double score = MatchEngine::calculateMatchScore(member, "Cloud");
        
        // Zero memory overhead leaks because unique_ptr cleans itself up automatically!
        cout << "Evaluated Profile Score: " << score << "%" << endl;
    }

    return 0;
}
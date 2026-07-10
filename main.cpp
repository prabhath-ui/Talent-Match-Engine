#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept> 
#include <fstream>    
#include <algorithm> 
#include "MatchEngine.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "Project.h"

using namespace std;

int main() {
    try {
        vector<unique_ptr<TeamMember>> talentRegistry;

        
        talentRegistry.push_back(make_unique<SoftwareEngineer>(
            "SE-02", "Charlie Cloud", 90.0, 6, 12, 
            std::unordered_set<string>{"Go", "Docker"}, true
        ));

        
        talentRegistry.push_back(make_unique<UXDesigner>(
    "UX-01", "Alice Design", 85.0, 7, 10, 
    std::unordered_set<string>{"Figma", "Wireframing"}
));

        
        talentRegistry.push_back(make_unique<SoftwareEngineer>(
            "SE-03", "Bob Junior", 60.0, 1, 2, 
            std::unordered_set<string>{"Python", "HTML"}, false
        ));

    
        Project cloudDeployment("PRJ-99", ProjectCategory::Cloud, {"Go", "Kubernetes"});

        
        vector<pair<double, TeamMember*>> rankedResults;

        for (const auto& member : talentRegistry) {
            double score = MatchEngine::calculateMatchScore(member, cloudDeployment);
            rankedResults.push_back({score, member.get()}); // .get() extracts the raw pointer safely
        }


        std::sort(rankedResults.begin(), rankedResults.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; // Retuns true if 'a' has a higher score than 'b'
        });

        
        ofstream reportFile("match_report.txt");
        if (!reportFile.is_open()) {
            throw runtime_error("Failed to open or create match_report.txt");
        }

       
        int rank = 1;
        for (const auto& result : rankedResults) {
            double score = result.first;
            TeamMember* member = result.second;

            // Output to terminal screen
            cout << "Rank " << rank << ": " << member->getId() << " - Match Score: " << score << "%\n";

            // Output exactly the same structured rankings to your file
            reportFile << "Rank " << rank << ": " << member->getId() << " - Match Score: " << score << "%\n";
            
            rank++;
        }

        reportFile.close();
        cout << "\n[Success] Ranked leaderboard exported to match_report.txt!" << endl;

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
#include <iostream>
#include <vector>
#include <string>
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "MatchEngine.h"

using namespace std;

int main() {
   vector<string> engSkills = {"Go", "Docker"};
    SoftwareEngineer charlie("SE-02", "Charlie Cloud", 90.0, 6, 12, engSkills, true);
    // Calc: Base 70 + 10 (FullStack) + 15 (Go) = 95. MatchEngine: +15 (Exp > 5) -> Clamped to 100%
    cout << "Charlie Score: " << MatchEngine::calculateMatchScore(&charlie, "Cloud") << "%" << endl;

    // 2. Test the UXDesigner
    vector<string> designerTools = {"Sketch", "Photoshop"}; // Lacks Figma
    UXDesigner dani("UX-01", "Dani Draft", 85.0, 2, 9, designerTools);
    // Calc: Base 70 - 30 (No Figma for Web) = 40. MatchEngine: +5 (Projects >= 8) -> 45%
    cout << "Dani Score: " << MatchEngine::calculateMatchScore(&dani, "Web") << "%" << endl;

    return 0;
}

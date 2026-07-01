#include <iostream>
#include <vector>
#include <string>
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
#include "MatchEngine.h"

using namespace std;

int main() {
   vector<string> engSkills = {"C++", "Python", "JavaScript"};
    SoftwareEngineer alice("SE-01", "Alice Dev", 75.0, 3, 9, engSkills, true);
    
    vector<string> designerTools = {"Figma", "Sketch"};
    UXDesigner bob("UX-01", "Bob Design", 65.0, 2, 4, designerTools, true);

    double aliceScore = MatchEngine::calculateMatchScore(&alice, "Enterprise");
    double bobScore = MatchEngine::calculateMatchScore(&bob, "Mobile");

    cout<<aliceScore<<"\n";
    cout<<bobScore;

    return 0;
}

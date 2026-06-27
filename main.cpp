#include <iostream>
#include <string>
#include "TeamMember.h"
#include "SoftwareEngineer.h"
#include "UXDesigner.h"
using namespace std;
int main() {
    TeamMember* team[2];
    team[0]=new SoftwareEngineer("E001","Alice Vance",75.50,5,12,"C++",true);
    team[1]=new UXDesigner("D001","Bob Ross",68.00,4,8,"Figma",true);
    for(auto it : team){
        string s=it->getFullName();
        cout<<s<<"\n";
    }
    delete team[0];
    delete team[1];
    return 0;
}

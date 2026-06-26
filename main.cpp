#include <iostream>
#include "TeamMember.h"

int main() {
    std::cout << "Attempting to create a generic TeamMember object..." << std::endl;

    // This line tries to instantiate our abstract class directly
    TeamMember testMember("EMP101", "Alex Mercer", 55.0, 5, 12);
    
    return 0;
}

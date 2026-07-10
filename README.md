# 🚀 Enterprise Talent Matching & Ranking Engine

An optimized, high-performance C++ matching engine that utilizes Object-Oriented Programming (OOP) architectures, robust error validation, and standard library data structures to evaluate and rank candidate suitability for technical project streams.

---

## 🛠️ System Architecture & Core Features

* **Polymorphic Talent Hierarchy:** Implements an abstract `TeamMember` base interface extended by specialized `SoftwareEngineer` and `UXDesigner` blueprints.
* **High-Performance Indexing:** Re-engineered core skill lookup structures from standard linear collections to hashed `std::unordered_set` structures, reducing lookup complexities from $O(N)$ down to **$O(1)$ constant time**.
* **Defensive Design & Fault Tolerance:** Leverages standard structural exceptions (`std::invalid_argument` and `std::runtime_error`) embedded within custom object constructors to block invalid states (e.g., negative experience values, corrupt tracking scores).
* **Persistence & Analytics reporting:** Integrates standard file output streams (`std::ofstream`) to auto-generate structured, audit-ready `.txt` reports mapping out evaluations directly to permanent storage.
* **Algorithmic Standings Sorting:** Utilizes modern C++ `<algorithm>` routines via `std::sort` combined with an embedded comparison **Lambda Expression** to dynamically reorder and rank a collection of team members into a prioritized leaderboard.

---

## 📁 Repository Structure

```text
├── main.cpp                # Execution entry point, runtime configuration, and try-catch handling
├── MatchEngine.h/.cpp     # Core scoring logic and polymorphic skill matching evaluation rules
├── TeamMember.h/.cpp       # Abstract parent class tracking structural metrics and shared properties
├── SoftwareEngineer.h/.cpp # Derived class capturing developer profiles and cert evaluations
├── UXDesigner.h/.cpp       # Derived class capturing designer profiles and wireframing variables
├── Project.h               # Encapsulated project requirements and structural profile configurations
├── ProjectCategory.h       # Strongly-typed enumeration defining execution verticals
└── match_report.txt        # Generated text report capturing runtime leaderboard results

#ifndef STAFF_PROJECT_H
#define STAFF_PROJECT_H

#include <set>
#include "ProjectManager.h"

class Project {
 public:
    Project(int id, int budget, int numberOfEmployees);
    ~Project();

    int getId() const;
    void setId(int id);
    int getBudget() const;
    void setBudget(int newBudget);
    int getNumberOfEmployees() const;
    void setNumberOfEmployees(int newNumberOfEmployees);

    void printProjectInfo() const;

 private:
    int id;
    int budget;
    int numberOfEmployees;
    ProjectManager* projectManager; 

    static std::set<int> occupiedIDs;
};


#endif //STAFF_PROJECT_H

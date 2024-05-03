#ifndef STAFF_PROJECT_H
#define STAFF_PROJECT_H

#include <set>

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
    void printProjectInfo();

 private:
    int id;
    int budget;
    int numberOfEmployees;

    static std::set<int> occupiedIDs;
};


#endif //STAFF_PROJECT_H

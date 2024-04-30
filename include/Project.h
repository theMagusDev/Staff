#ifndef STAFF_PROJECT_H
#define STAFF_PROJECT_H

#include <set>

class Project {
 public:
    Project(int id, unsigned int budget, unsigned int numberOfEmployees);
    ~Project();

    int getId() const;
    void setId(int id);
    unsigned int getBudget() const;
    void setBudget(unsigned int budget);
    unsigned int getNumberOfEmployees() const;
    void setNumberOfEmployees(unsigned int numberOfEmployees);

private:
    int id;
    unsigned int budget;
    unsigned int numberOfEmployees;

    static std::set<int> occupiedIDs;
};


#endif //STAFF_PROJECT_H

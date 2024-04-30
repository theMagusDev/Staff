#include <iostream>
#include "../include/Project.h"

std::set<int> Project::occupiedIDs;

Project::Project(
    int id,
    unsigned int budget,
    unsigned int numberOfEmployees
) : budget(budget), numberOfEmployees(numberOfEmployees) {
    setId(id);
}

Project::~Project() {
    occupiedIDs.erase(this->id);
    this->id = -1;
    this->budget = 0;
    this->numberOfEmployees = 0;
}

int Project::getId() const {
    return id;
}

void Project::setId(int newId) {
    bool IDisOccupied =
            Project::occupiedIDs.find(newId) != Project::occupiedIDs.end();
    if (!IDisOccupied && newId >= 0) {
        this->id = newId;
        Project::occupiedIDs.insert(newId);
    } else {
        if (IDisOccupied) {
            std::cerr << "Error in project " << getId()
                      << ": duplicated project ID" << std::endl;
        } else {
            std::cerr << "Error in project " << getId()
                      << ": project ID mustn't be negative" << std::endl;
        }
    }
}

unsigned int Project::getBudget() const {
    return budget;
}

void Project::setBudget(unsigned int budget) {
    this->budget = budget;
}

unsigned int Project::getNumberOfEmployees() const {
    return this->numberOfEmployees;
}

void Project::setNumberOfEmployees(unsigned int numberOfEmployees) {
    this->numberOfEmployees = numberOfEmployees;
}

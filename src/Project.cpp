#include <iostream>
#include "../include/Project.h"
#include "../include/Exception.h"

std::set<int> Project::occupiedIDs;

Project::Project(
    int id,
    int budget,
    int numberOfEmployees
) {
    setId(id);
    setBudget(budget);
    setNumberOfEmployees(numberOfEmployees);
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
            throw InvalidProjectIDException(
                "Exception in project "
                + std::to_string( getId())
                + ": duplicated project ID"
            );
        } else {
            throw InvalidProjectIDException(
                "Exception in project "
                + std::to_string(getId())
                + ": project ID mustn't be negative"
            );
        }
    }
}

int Project::getBudget() const {
    return budget;
}

void Project::setBudget(int newBudget) {
    if (newBudget < 0) {
        throw InvalidProjectBudgetException(
            "Project budget can not be negative"
        );
    } else {
        this->budget = newBudget;
    }
}

int Project::getNumberOfEmployees() const {
    return this->numberOfEmployees;
}

void Project::setNumberOfEmployees(int newNumberOfEmployees) {
    if (newNumberOfEmployees < 0) {
        throw InvalidNumberOfEmployeesException(
            "Employees number can not be negative"
        );
    } else {
        this->numberOfEmployees = newNumberOfEmployees;
    }
}

void Project::printProjectInfo() const {
    std::cout << "Project #" << getId() << std::endl;
    std::cout << " Number of employees: "
        << getNumberOfEmployees() << std::endl;
}

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
    clearManagerId();
}

Project::Project(
        int id,
        int budget,
        int numberOfEmployees,
        int managerId
) {
    setId(id);
    setBudget(budget);
    setNumberOfEmployees(numberOfEmployees);
    setManagerId(managerId);
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
            throw InvalidProjectIDException((
                "Exception in project "
                + std::to_string( getId())
                + ": duplicated project ID"
            ).c_str());
        } else {
            throw InvalidProjectIDException((
                "Exception in project "
                + std::to_string(getId())
                + ": project ID mustn't be negative"
            ).c_str());
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
    std::cout << " Budget: " << getBudget() << std::endl;
    if (getManagerId() != -1) {
        std::cout << " Manager ID: " << getManagerId() << std::endl;
    } else {
        std::cout << " No manager" << std::endl;
    }
}

int Project::getManagerId() const {
    return managerID;
}

void Project::setManagerId(int managerId) {
    if (managerId < 0) {
        throw InvalidProjectManagerIDException("Project's manager ID must not be negative");
    } else {
        this->managerID = managerId;
    }
}

void Project::clearManagerId() {
    this->managerID = -1;
}

bool Project::hasManager() const {
    return getManagerId() != -1;
}

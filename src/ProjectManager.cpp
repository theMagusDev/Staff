#define PAYMENT_PER_PERSON_IN_PROJECT 5000
#define BONUS_FOR_BIG_PROJECT 30000
#define BIG_PROJECT_CRITERIA 7
#define PROJECT_MANAGER_PART 0.25

#include <cmath>
#include <iostream>
#include "../include/ProjectManager.h"

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        Position position
) : Employee(id, name, position) {
    projects = *(new std::vector<Project*>(1));
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        Position position,
        Project& project
) : ProjectManager(id, name, position) {
    projects[0] = &project;
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        Position position,
        int worktime
) : Employee(id, name, position, worktime) {
    projects = *(new std::vector<Project*>(1));
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        Position position,
        int worktime,
        Project& project
) : ProjectManager(id, name, position, worktime) {
    projects[0] = &project;
}

int ProjectManager::calculateProAdditions() {
    bool hasProject = projects[0] != nullptr;
    if (!hasProject) {
        return 0;
    }

    if(projects[0]->getNumberOfEmployees() >= BIG_PROJECT_CRITERIA) {
        return BONUS_FOR_BIG_PROJECT;
    } else {
        return 0;
    }
}

int ProjectManager::calculateHeads() {
    if (projects[0] == nullptr) {
        return 0;
    }

    return PAYMENT_PER_PERSON_IN_PROJECT * projects[0]->getNumberOfEmployees();
}

int ProjectManager::calculateBudgetPart(float part, int budget) {
    return std::ceil(static_cast<float>(budget) * part);
}

void ProjectManager::calculatePayment() {
    if (projects[0] != nullptr) {
        setPayment(
            calculateHeads()
            + calculateProAdditions()
            + calculateBudgetPart(
                PROJECT_MANAGER_PART,
                projects[0]->getBudget()
            )
        );
    } else {
        setPayment(calculateHeads() + calculateProAdditions());
    }
}

void ProjectManager::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;

}



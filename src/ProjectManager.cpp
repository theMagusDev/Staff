#define PAYMENT_PER_PERSON_IN_PROJECT 5000
#define BONUS_FOR_BIG_PROJECT 30000
#define BIG_PROJECT_CRITERIA 7
#define PROJECT_MANAGER_PART 0.25

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
    projects[0] = nullptr;
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

int ProjectManager::calculateProAdditions() const {
    if (!hasProject()) {
        return 0;
    }

    if(projects[0]->getNumberOfEmployees() >= BIG_PROJECT_CRITERIA) {
        return BONUS_FOR_BIG_PROJECT;
    } else {
        return 0;
    }
}

int ProjectManager::calculateHeads() const {
    if (!hasProject()) {
        return 0;
    }

    return PAYMENT_PER_PERSON_IN_PROJECT * (projects[0]->getNumberOfEmployees() - 1);
}

void ProjectManager::calculatePayment() {
    if (hasProject()) {
        setPayment(
            calculateHeads()
            + calculateProAdditions()
            + calculateBudgetPart(
                    projects[0],
                    PROJECT_MANAGER_PART)
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
    if (hasProject()) {
        std::cout << " Project: " << std::endl;
        projects[0]->printProjectInfo();
    }
}

bool ProjectManager::hasProject() const {
    return this->projects[0] != nullptr;
}

Project* ProjectManager::getProject() const {
    if (projects.empty()) {
        return nullptr;
    }

    return this->projects[0];
}

void ProjectManager::setProject(Project* newProject) {
    if (newProject == nullptr) {
        return;
    }

    if (projects.empty()) {
        projects.push_back(newProject);
    } else {
        this->projects[0] = newProject;
    }
}



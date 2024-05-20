#define PAYMENT_PER_PERSON_IN_PROJECT 5000
#define BONUS_FOR_BIG_PROJECT 30000
#define BIG_PROJECT_CRITERIA 7
#define PROJECT_MANAGER_PART 0.25

#include <iostream>
#include "../include/ProjectManager.h"

ProjectManager::ProjectManager(
        int id,
        const std::string& name
) : Employee(id, name) {
    setPosition(Position::PROJECT_MANAGER);
    projects = *(new std::vector<Project*>(1));
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        Project* project
) : ProjectManager(id, name) {
    setProject(project);
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        int worktime
) : Employee(id, name, worktime) {
    setPosition(Position::PROJECT_MANAGER);
    projects = *(new std::vector<Project*>(1));
    projects[0] = nullptr;
}

ProjectManager::ProjectManager(
        int id,
        const std::string& name,
        int worktime,
        Project* project
) : ProjectManager(id, name, worktime) {
    setPosition(Position::PROJECT_MANAGER);
    setProject(project);
}

ProjectManager::~ProjectManager() {
    for (Project* project : projects) {
        project->clearManagerId();
    }
    projects.clear();
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
                    projects[0]->getBudget(),
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

void ProjectManager::clearProject() {
    if (hasProject()) {
        this->getProject()->clearManagerId();
        this->projects[0] = nullptr;
    }
}

void ProjectManager::setProject(Project* newProject) {
    if (newProject == nullptr || newProject == this->getProject()) {
        return;
    }

    if (newProject->hasManager() && newProject->getManagerId() != this->getId()) {
        std::cerr << "Error in Project manager " << getName()
                  << ": project " << newProject->getId()
                  << " already has manager with ID "
                  << newProject->getManagerId()
                  << ". Clear it first using clearManager() method." << std::endl;
    } else {
        if (projects.empty()) {
            projects.push_back(newProject);
            if (projects[0]->getManagerId() != this->getId()) {
                projects[0]->setManagerId(this->getId());
            }
        } else {
            this->projects[0] = newProject;
            if (newProject->getManagerId() != this->getId()) {
                projects[0]->setManagerId(this->getId());
            }
        }
    }
}

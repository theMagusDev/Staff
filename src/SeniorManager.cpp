#define PAYMENT_PER_PERSON_IN_PROJECT 6000
#define BONUS_FOR_BIG_PROJECT 50000
#define BIG_PROJECT_CRITERIA 9
#define SENIOR_MANAGER_PART 0.20

#include <cmath>
#include <iostream>
#include "../include/SeniorManager.h"

SeniorManager::SeniorManager(
        int id,
        const std::string& name
) : ProjectManager(id, name) {}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        int workTime
) : ProjectManager(id, name, workTime) {}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        std::vector<Project*>& projects
) : ProjectManager(id, name) {
    // check vector for unavailable projects
    std::vector<Project*> checkedProjects;
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->getManagerId() == -1) {
            std::cerr << "Error in Senior manager " << name
                      << " constructor: project " << projects[i]->getId()
                      << " already has manager with ID "
                      << projects[i]->getManagerId()
                      << ", clear it first using clearManager method." << std::endl;
        } else {
            checkedProjects.push_back(projects[i]);
            projects[i]->setManagerId(this->getId());
        }
    }
    this->projects = checkedProjects;
}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        int workTime,
        std::vector<Project*>& projects
) : ProjectManager(id, name) {
    setPosition(Position::PROJECT_MANAGER);
    setWorkTime(workTime);
    // check vector for unavailable projects
    std::vector<Project*> checkedProjects;
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->getManagerId() == -1) {
            std::cerr << "Error in Senior manager " << name
                      << " constructor: project " << projects[i]->getId()
                      << " already has manager with ID "
                      << projects[i]->getManagerId()
                      << ", clear it first using clearManager method." << std::endl;
        } else {
            checkedProjects.push_back(projects[i]);
            projects[i]->setManagerId(this->getId());
        }
    }
    this->projects = checkedProjects;
}

int SeniorManager::calculateHeads() const {
    if (!hasProject()) {
        return 0;
    }

    int result = 0;
    for (Project* project : projects) {
        result += PAYMENT_PER_PERSON_IN_PROJECT * (project->getNumberOfEmployees() - 1);
    }
    return result;
}

int SeniorManager::calculateProAdditions() const {
    if (!hasProject()) {
        return 0;
    }

    int result = 0;
    for (Project* project : projects) {
        if(project->getNumberOfEmployees() >= BIG_PROJECT_CRITERIA) {
            result += BONUS_FOR_BIG_PROJECT;
        }
    }
    return result;
}

int SeniorManager::calculateBudgetsPart(float part) const {
    if (!hasProject()) {
        return 0;
    }

    int result = 0;
    for (Project* project : projects) {
        result += calculateBudgetPart(
                project->getBudget(),
                part
                );
    }
    return result;
}

void SeniorManager::calculatePayment() {
    setPayment(
        calculateHeads()
        + calculateProAdditions()
        + calculateBudgetsPart(SENIOR_MANAGER_PART)
    );
}

void SeniorManager::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
    std::cout << " Projects: " << getPayment() << std::endl;
    if (!hasProject()) {
        std::cout << "  No projects" << std::endl;
    } else {
        for (Project* project : projects) {
            std::cout << "  ";
            project->printProjectInfo();
        }
    }
}

std::vector<Project*> SeniorManager::getProjects() const {
    return this->projects;
}

void SeniorManager::addProject(Project* newProject) {
    if (newProject == nullptr) {
        return;
    }

    if (newProject->hasManager()) {
        std::cerr << "Error in Senior manager " << getName()
                  << ": project " << newProject->getId()
                  << " already has manager with ID "
                  << newProject->getManagerId()
                  << ", clear it first using clearManager method." << std::endl;
    } else {
        this->projects.push_back(newProject);
        newProject->setManagerId(this->getId());
    }
}

Project* SeniorManager::popProject(int projectID) {
    Project* hold = nullptr;
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->getId() == projectID) {
            hold = projects[i];
            projects.erase(projects.begin() + i);
        }
    }

    if (hold != nullptr) {
        hold->clearManagerId();
    }
    return hold;
}

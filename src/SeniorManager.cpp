#define PAYMENT_PER_PERSON_IN_PROJECT 6000
#define BONUS_FOR_BIG_PROJECT 50000
#define BIG_PROJECT_CRITERIA 9
#define SENIOR_MANAGER_PART 0.20

#include <cmath>
#include <iostream>
#include "../include/SeniorManager.h"

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        Position position
) : ProjectManager(id, name, position) {}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        Position position,
        int workTime
) : ProjectManager(id, name, position, workTime) {}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        Position position,
        std::vector<Project*>& projects
) : ProjectManager(id, name, position) {
    // check vector for unavailable projects
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->hasManager()) {
            std::cerr << "Error in Senior manager " << name
                      << "constructor: project " << projects[i]->getId()
                      << " already has manager" << std::endl;
            projects.erase(projects.begin() + i);
        } else {
            projects[i]->setHasManager(true);
        }
    }
    this->projects = projects;
}

SeniorManager::SeniorManager(
        int id,
        const std::string& name,
        Position position,
        int workTime,
        std::vector<Project*>& projects
) : ProjectManager(id, name, position) {
    // check vector for unavailable projects
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i]->hasManager()) {
            std::cerr << "Error in Senior manager " << name
                      << "constructor: project " << projects[i]->getId()
                      << " already has manager" << std::endl;
            projects.erase(projects.begin() + i);
        } else {
            projects[i]->setHasManager(true);
        }
    }
    this->projects = projects;
    setWorkTime(workTime);
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
                project,
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
                  << " already has manager" << std::endl;
    } else {
        this->projects.push_back(newProject);
        newProject->setHasManager(true);
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

    hold->setHasManager(false);
    return hold;
}

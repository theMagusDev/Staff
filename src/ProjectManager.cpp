#define PAYMENT_PER_PERSON_IN_PROJECT 5000
#define BONUS_FOR_BIG_PROJECT 30000
#define BIG_PROJECT_CRITERIA 7
#define PROJECT_MANAGER_PART 0.25

#include <iostream>
#include "../include/ProjectManager.h"
#include "../include/Employee.h"



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
        Project& project
) : ProjectManager(id, name) {
    if (project.hasManager()) {
        std::cerr << "Error in Project manager " << name
        << " constructor: project " << project.getId()
        << " already has manager" << std::endl;
        projects[0] = nullptr;
    } else {
        projects[0] = &project;
        projects[0]->setHasManager(true);
    }
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
        Project& project
) : ProjectManager(id, name, worktime) {
    setPosition(Position::PROJECT_MANAGER);
    if (project.hasManager()) {
        std::cerr << "Error in Project manager " << name
                  << " constructor: project " << project.getId()
                  << " already has manager" << std::endl;
        projects[0] = nullptr;
    } else {
        projects[0] = &project;
        projects[0]->setHasManager(true);
    }
}

ProjectManager::~ProjectManager() {
    for (Project* project : projects) {
        project->setHasManager(false);
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

void ProjectManager::setProject(Project* newProject) {
    if (newProject == nullptr) {
        return;
    }

    if (projects.empty()) {
        projects.push_back(newProject);
        projects[0]->setHasManager(true);
    } else {
        if (newProject->hasManager()) {
            std::cerr << "Error in Project manager " << getName()
                      << ": project " << newProject->getId()
                      << " already has manager" << std::endl;
        } else {
            projects[0]->setHasManager(false);
            this->projects[0] = newProject;
            projects[0]->setHasManager(true);
        }
    }
}

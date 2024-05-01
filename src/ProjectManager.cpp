#define BONUS_PER_PERSON_IN_PROJECT 5000

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

int ProjectManager::calcHeads() {
    if (projects[0] == nullptr) {
        return 0;
    }

    return BONUS_PER_PERSON_IN_PROJECT * projects[0]->getNumberOfEmployees();
}



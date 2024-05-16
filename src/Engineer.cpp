#include "../include/Engineer.h"

Engineer::Engineer(
        int id,
        const std::string& name,
        Position position,
        int hourlyRate,
        Project* project
) : Personal(id, name, position, hourlyRate) {
    setProject(project);
}

Engineer::Engineer(
        int id,
        const std::string& name,
        Position position,
        int hourlyRate,
        int worktime,
        Project* project
) : Personal(id, name, position, hourlyRate, worktime) {
    setProject(project);
}

Project* Engineer::getProject() const {
    return project;
}

void Engineer::setProject(Project* newProject) {
    Engineer::project = newProject;
}



#ifndef STAFF_PROJECTMANAGER_H
#define STAFF_PROJECTMANAGER_H

#include <vector>
#include <string>
#include "Project.h"
#include "Employee.h"
#include "Heading.h"

class ProjectManager : protected Employee, public Heading {
 public:
    ProjectManager(int id, const std::string& name, Position position);
    ProjectManager(int id, const std::string& name, Position position, Project& project);
    ProjectManager(int id, const std::string& name, Position position, size_t worktime);
    ProjectManager(int id, const std::string& name, Position position, size_t worktime, Project& project);

    int calcHeads() override;

private:
    std::vector<Project*> projects;
};


#endif //STAFF_PROJECTMANAGER_H

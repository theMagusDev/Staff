#ifndef STAFF_PROJECTMANAGER_H
#define STAFF_PROJECTMANAGER_H

#include <vector>
#include "Project.h"

class ProjectManager {
 public:
    ProjectManager();
 private:
    std::vector<Project*> projects;
};


#endif //STAFF_PROJECTMANAGER_H

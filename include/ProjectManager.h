#ifndef STAFF_PROJECTMANAGER_H
#define STAFF_PROJECTMANAGER_H

#include <vector>
#include <string>
#include "Project.h"
#include "Employee.h"
#include "Heading.h"
#include "ProjectBudget.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 public:
    ProjectManager(int id, const std::string& name);
    ProjectManager(int id, const std::string& name, Project& project);
    ProjectManager(int id, const std::string& name, int worktime);
    ProjectManager(int id, const std::string& name, int worktime, Project& project);
    ~ProjectManager() override;

    Project* getProject() const;
    void setProject(Project* newProject);

    void calculatePayment() override;
    void printInfo() override;

 protected:
    std::vector<Project*> projects;
    bool hasProject() const;

 private:
    int calculateHeads() const override;
    int calculateProAdditions() const override;
};


#endif //STAFF_PROJECTMANAGER_H

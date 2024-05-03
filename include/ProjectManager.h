#ifndef STAFF_PROJECTMANAGER_H
#define STAFF_PROJECTMANAGER_H

#include <vector>
#include <string>
#include "Project.h"
#include "Employee.h"
#include "Heading.h"
#include "ProjectBudget.h"

class ProjectManager : protected Employee, public Heading, public ProjectBudget {
 public:
    ProjectManager(int id, const std::string& name, Position position);
    ProjectManager(int id, const std::string& name, Position position, Project& project);
    ProjectManager(int id, const std::string& name, Position position, int worktime);
    ProjectManager(int id, const std::string& name, Position position, int worktime, Project& project);

    void calculatePayment() override;
    void printInfo() override;

 private:
    std::vector<Project*> projects;
    bool hasProject() const;

    int calculateHeads() const override;
    int calculateProAdditions() const override;
    int calculateBudgetPart(float part, int budget) const override;
};


#endif //STAFF_PROJECTMANAGER_H

#ifndef STAFF_SENIORMANAGER_H
#define STAFF_SENIORMANAGER_H

#include "ProjectManager.h"

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id, const std::string& name);
    SeniorManager(int id, const std::string& name, std::vector<Project*>& projects);
    SeniorManager(int id, const std::string& name, int worktime);
    SeniorManager(int id, const std::string& name, int worktime, std::vector<Project*>& projects);

    std::vector<Project*> getProjects() const;
    void addProject(Project* newProject);
    Project* popProject(int projectID);

    void calculatePayment() override;
    void printInfo() override;

 private:
    int calculateHeads() const override;
    int calculateProAdditions() const override;
    int calculateBudgetsPart(float part) const;
};


#endif // STAFF_SENIORMANAGER_H

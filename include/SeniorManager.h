#ifndef STAFF_SENIORMANAGER_H
#define STAFF_SENIORMANAGER_H

#include "ProjectManager.h"

class SeniorManager : protected ProjectManager {
 public:
    SeniorManager(int id, const std::string& name, Position position);
    SeniorManager(int id, const std::string& name, Position position, std::vector<Project*>& projects);
    SeniorManager(int id, const std::string& name, Position position, int worktime);
    SeniorManager(int id, const std::string& name, Position position, int worktime, std::vector<Project*>& projects);

    void calculatePayment() override;
    void printInfo() override;

 private:
    int calculateHeads() const override;
    int calculateProAdditions() const override;
    int calculateBudgetsPart(float part) const;
};


#endif // STAFF_SENIORMANAGER_H

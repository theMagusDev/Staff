#ifndef STAFF_TESTER_H
#define STAFF_TESTER_H

#include "Engineer.h"
#include "Project.h"

class Tester : public Engineer {
 public:
    Tester(int id, const std::string& name, int hourlyRate, Project* project, int bugsFound = 0);
    Tester(int id, const std::string& name, int hourlyRate, int worktime, Project* project, int bugsFound = 0);

    int getBugsFound() const;
    void setBugsFound(int bugsFound);
    void incrementBugsFound();

    void calculatePayment() override;
    void printInfo() override;

 private:
    int bugsFound;

    int calculateProAdditions() const override;
    int calculateBonus() const override;
};


#endif //STAFF_TESTER_H

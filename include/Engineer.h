#ifndef STAFF_ENGINEER_H
#define STAFF_ENGINEER_H

#include "Personal.h"
#include "Project.h"

class Engineer : public Personal {
 public:
    Engineer(int id, const std::string& name, int hourlyRate);
    Engineer(int id, const std::string& name, int hourlyRate, int worktime);

    void calculatePayment() override;
    void printInfo() override;

 private:
    Project* project;
};


#endif // STAFF_ENGINEER_H

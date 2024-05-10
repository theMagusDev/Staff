#ifndef STAFF_DRIVER_H
#define STAFF_DRIVER_H

#include "Personal.h"

class Driver : Personal {
 public:
    Driver(int id, const std::string& name, int nightHours);
    Driver(int id, const std::string& name, int worktime, int nightHours;

    void calculatePayment() override;
    void printInfo() override;

 private:
    int calculateBase() const override;
    int calculateBonus() const override;

    int nightHours;
};


#endif //STAFF_DRIVER_H

#ifndef STAFF_DRIVER_H
#define STAFF_DRIVER_H

#include "Personal.h"

class Driver : public Personal {
 public:
    Driver(int id, const std::string& name, int horlyRate);
    Driver(int id, const std::string& name, int hourlyRate, int nightHours, int worktime);

    int getNightHours() const;
    void setNightHours(int nightHours);

    void calculatePayment() override;
    void printInfo() override;

 private:
    int calculateBase() const override;
    int calculateBonus() const override;

    int nightHours;
};


#endif //STAFF_DRIVER_H

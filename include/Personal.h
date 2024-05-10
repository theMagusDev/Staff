#ifndef STAFF_PERSONAL_H
#define STAFF_PERSONAL_H

#include "Employee.h"
#include "WorkBaseTime.h"

class Personal : protected Employee, public WorkBaseTime {
 public:
    Personal(int id, const std::string& name, Position position, int hourlyRate);
    Personal(int id, const std::string &name, Position position, int hourlyRate, int worktime);

    int getHourlyRate() const;
    void setHourlyRate(int newHourlyRate);

    int calculateBase() const override;

 protected:
    int hourlyRate;
};


#endif //STAFF_PERSONAL_H

#ifndef STAFF_PERSONAL_H
#define STAFF_PERSONAL_H

#include "Employee.h"
#include "WorkBaseTime.h"

class Personal : protected Employee, public WorkBaseTime {
 public:
    Personal(int id, const std::string& name, Position position);
    Personal(int id, const std::string &name, Position position, int worktime);

    int calculateBase() const override;
};


#endif //STAFF_PERSONAL_H

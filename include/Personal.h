#ifndef STAFF_PERSONAL_H
#define STAFF_PERSONAL_H

#include "Employee.h"
#include "WorkBaseTime.h"

class Personal : protected Employee, public WorkBaseTime {
 public:
    Personal(int id, const std::string& name, Position position, int salary);
    Personal(int id, const std::string &name, Position position, int worktime, int salary);

    int getSalary() const;
    void setSalary(int newSalary);

    int calculateBase() const override;

 private:
    int salary;
};


#endif //STAFF_PERSONAL_H

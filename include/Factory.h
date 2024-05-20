#ifndef STAFF_FACTORY_H
#define STAFF_FACTORY_H

#include <vector>
#include <map>
#include "Employee.h"

class Factory {
 public:
    static std::vector<Employee*> makeStaff();
};


#endif //STAFF_FACTORY_H

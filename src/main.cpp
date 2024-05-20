#include <iostream>
#include "../include/Factory.h"

int main() {
    std::vector<Employee*> staff = Factory::makeStaff();
    for (Employee* employee : staff) {
        employee->printInfo();
    }

    return 0;
}


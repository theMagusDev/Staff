#ifndef STAFF_WORKBASETIME_H
#define STAFF_WORKBASETIME_H

#include <iostream>

class WorkBaseTime {
    virtual ~WorkBaseTime() = default;
    virtual int calcBase(int salary, size_t workTime) = 0;
};

#endif //STAFF_WORKBASETIME_H

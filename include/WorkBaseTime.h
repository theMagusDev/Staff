#ifndef STAFF_WORKBASETIME_H
#define STAFF_WORKBASETIME_H

#include <iostream>

class WorkBaseTime {
 public:
    virtual ~WorkBaseTime() = default;
    virtual int calcBase() = 0;
};

#endif //STAFF_WORKBASETIME_H

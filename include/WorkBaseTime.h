#ifndef STAFF_WORKBASETIME_H
#define STAFF_WORKBASETIME_H

#include <iostream>

class WorkBaseTime {
 public:
    virtual ~WorkBaseTime() = default;
    virtual int calculateBase() const = 0;
    virtual int calculateBonus() const = 0;
};

#endif //STAFF_WORKBASETIME_H

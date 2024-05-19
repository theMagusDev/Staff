#ifndef STAFF_PROJECTBUDGET_H
#define STAFF_PROJECTBUDGET_H

#include <cmath>
#include "Project.h"

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;
    virtual int calculateProAdditions() const = 0;
    static int calculateBudgetPart(int projectBudget, float part) {
        return std::ceil(static_cast<float>(projectBudget) * part);
    }
};

#endif //STAFF_PROJECTBUDGET_H

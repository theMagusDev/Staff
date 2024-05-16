#ifndef STAFF_PROJECTBUDGET_H
#define STAFF_PROJECTBUDGET_H

#include <cmath>
#include "Project.h"

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;
    virtual int calculateProAdditions() const = 0;
    static int calculateBudgetPart(Project* project, float part) {
        if (project == nullptr) {
            return 0;
        }
        return std::ceil(static_cast<float>(project->getBudget()) * part);
    }
};

#endif //STAFF_PROJECTBUDGET_H

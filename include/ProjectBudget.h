#ifndef STAFF_PROJECTBUDGET_H
#define STAFF_PROJECTBUDGET_H

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;
    virtual int calculateBudgetPart(Project* project) const = 0;
    virtual int calculateProAdditions() const = 0;
};

#endif //STAFF_PROJECTBUDGET_H

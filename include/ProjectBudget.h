#ifndef STAFF_PROJECTBUDGET_H
#define STAFF_PROJECTBUDGET_H

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;
    virtual int calculateBudgetPart(float part, int budget) = 0;
    virtual int calculateProAdditions() = 0;
};

#endif //STAFF_PROJECTBUDGET_H

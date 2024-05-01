#ifndef STAFF_PROJECTBUDGET_H
#define STAFF_PROJECTBUDGET_H

class ProjectBudget {
    virtual ~ProjectBudget() = default;
    virtual int calcBudgetpart(float part, int budget) = 0;
};

#endif //STAFF_PROJECTBUDGET_H
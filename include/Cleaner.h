#ifndef STAFF_CLEANER_H
#define STAFF_CLEANER_H

#include "Personal.h"

class Cleaner : public Personal {
 public:
    Cleaner(int id, const std::string& name);
    Cleaner(int id, const std::string& name, int worktime);

    void calculatePayment() override;
    void printInfo() override;

 private:
    int calculateBonus() const override;
};


#endif // STAFF_CLEANER_H

#include "../include/Cleaner.h"

#define BONUS_WORKTIME_CRITERIA 720

Cleaner::Cleaner(
        int id,
        const std::string& name
) : Personal(id, name, Position::CLEANER) {}

Cleaner::Cleaner(
        int id,
        const std::string& name,
        int worktime
) : Personal(id, name, Position::CLEANER, worktime) {}

void Cleaner::calculatePayment() {
    setPayment(calculateBase() + calculateBonus());
}

int Cleaner::calculateBase() const {
    return worktime * payment;
}

int Cleaner::calculateBonus() const {
    if (worktime > BONUS_WORKTIME_CRITERIA) {
        return 5000;
    } else {
        return 0;
    }
}

void Cleaner::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
}

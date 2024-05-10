#include "../include/Driver.h"

#define BONUS_WORKTIME_CRITERIA 720

Driver::Driver(
        int id,
        const std::string& name
) : Personal(id, name, Position::DRIVER) {}

Driver::Driver(
        int id,
        const std::string& name,
        int worktime
) : Personal(id, name, Position::DRIVER, worktime) {}

void Driver::calculatePayment() {
    setPayment(calculateBase() + calculateBonus());
}

int Driver::calculateBase() const {
    return worktime * payment;
}

int Driver::calculateBonus() const {
    if (worktime > BONUS_WORKTIME_CRITERIA) {
        return 5000;
    } else {
        return 0;
    }
}

void Driver::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
}

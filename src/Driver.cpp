#include "../include/Driver.h"
#include "../include/Exception.h"

#define BONUS_WORKTIME_CRITERIA 720
#define NIGHT_HOURS_BONUS 400

Driver::Driver(
        int id,
        const std::string& name,
        int horlyRate
) : Personal(id, name, Position::DRIVER, horlyRate) {}

Driver::Driver(
        int id,
        const std::string& name,
        int hourlyRate,
        int nightHours,
        int worktime
) : Personal(id, name, Position::DRIVER, hourlyRate, worktime) {
    setNightHours(nightHours);
}

void Driver::calculatePayment() {
    setPayment(calculateBase() + calculateBonus());
}

int Driver::calculateBonus() const {
    return getNightHours() * NIGHT_HOURS_BONUS;
}

void Driver::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
}

int Driver::getNightHours() const {
    return nightHours;
}

void Driver::setNightHours(int newNightHours) {
    if (newNightHours > worktime) {
        throw InvalidNightHoursException("Night hours can not be more than total worktime");
    }
    if (newNightHours < 0) {
        throw InvalidNightHoursException("Night hours can not be negative");
    }

    this->nightHours = newNightHours;
}

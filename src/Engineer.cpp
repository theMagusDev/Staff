#include "../include/Engineer.h"

Engineer::Engineer(
        int id,
        const std::string& name,
        int hourlyRate
) : Personal(id, name, Position::CLEANER, hourlyRate) {}

Engineer::Engineer(
        int id,
        const std::string& name,
        int hourlyRate,
        int worktime
) : Personal(id, name, Position::CLEANER, hourlyRate, worktime) {}

void Engineer::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Hourly rate: " << getHourlyRate() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
}

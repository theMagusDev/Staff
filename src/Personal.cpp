#include "../include/Personal.h"
#include "../include/Exception.h"

#define DAILY_HOURS_WORKED 9

Personal::Personal(
        int id,
        const std::string& name,
        Position position,
        int hourlyRate
) : Employee(id, name, position) {
    setHourlyRate(hourlyRate);
}

Personal::Personal(
        int id,
        const std::string& name,
        Position position,
        int worktime,
        int hourlyRate
) : Personal(id, name, position, hourlyRate) {
    setWorkTime(worktime);
}

int Personal::calculateBase() const {
    return hourlyRate * DAILY_HOURS_WORKED * getWorkTime();
}

int Personal::getHourlyRate() const {
    return hourlyRate;
}

void Personal::setHourlyRate(int newHourlyRate) {
    if (newHourlyRate < 0) {
        throw InvalidHourlyRateException("Hourly rate can not be negative");
    } else {
        this->hourlyRate = newHourlyRate;
    }
}

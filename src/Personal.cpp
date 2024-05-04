#include "../include/Personal.h"
#include "../include/Exception.h"

Personal::Personal(
        int id,
        const std::string& name,
        Position position
) : Employee(id, name, position) {}

Personal::Personal(
        int id,
        const std::string& name,
        Position position,
        int worktime
) : Personal(id, name, position) {
    setWorkTime(worktime);
}

int Personal::calculateBase() const {
    return payment * getWorkTime();
}

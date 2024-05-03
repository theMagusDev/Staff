#include "../include/Personal.h"
#include "../include/Exception.h"

Personal::Personal(
        int id,
        const std::string& name,
        Position position,
        int salary
) : Employee(id, name, position) {
    setSalary(salary);
}

Personal::Personal(
        int id,
        const std::string& name,
        Position position,
        int worktime,
        int salary
) : Personal(id, name, position, salary) {
    setWorkTime(worktime);
}

int Personal::getSalary() const {
    return this->salary;
}

void Personal::setSalary(int newSalary) {
    if (newSalary < 0) {
        throw InvalidSalaryException("Salary mustn't be negative");
    } else {
        this->salary = newSalary;
    }
}

int Personal::calcBase() {
    return salary * getWorkTime();
}

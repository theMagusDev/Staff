#include <string>
#include <iostream>
#include <chrono>
#include "../include/Employee.h"
#include "../include/Exception.h"

std::set<int> Employee::occupiedIDs;

Employee::Employee(
        int id,
        const std::string& name,
        Position position
) : id(id), name(name), position(position) {
    this->payment = -1;
    this->worktime = 0;
    if (Employee::isNameCorrect(name)) {
        this->name = name;
    } else {
        throw InvalidNameException(
                "Invalid name! Only English letters and '-' are allowed; "
                "0 < length <= 34. Got " + name);
    }
}

Employee::Employee(
    int id,
    const std::string& name,
    Position position,
    size_t worktime
) : Employee(id, name, position) {
    this->worktime = worktime;
}

Employee::~Employee() {
    occupiedIDs.erase(this->id);
    this->id = -1;
    this->name.clear();
    this->position = Position::UNINITIALIZED;
    this->payment = -1;
    this->worktime = 0;
}

const std::string& Employee::getName() const {
    return name;
}

void Employee::setName(const std::string& newName) {
    this->name = newName;
}

const std::string& Employee::getPosition() const {
    switch (this->position) {
        case (Position::TEAM_LEADER):
            return *(new std::string("Team leader"));
        case Position::UNINITIALIZED:
            return *(new std::string("Not initialized"));
        case Position::PROGRAMMER:
            return *(new std::string("Programmer"));
        case Position::TESTER:
            return *(new std::string("Tester"));
        case Position::PROJECT_MANAGER:
            return *(new std::string("Project manager"));
        case Position::SENIOR_MANAGER:
            return *(new std::string("Senior manager"));
        case Position::DRIVER:
            return *(new std::string("Driver"));
        case Position::CLEANER:
            return *(new std::string("Cleaner"));
        default:
            return *(new std::string("Unknown"));
    }
}

void Employee::setPosition(Position newPosition) {
    this->position = newPosition;
}

int Employee::getPayment() const {
    return payment;
}

void Employee::setPayment(int newPayment) {
    this->payment = newPayment;
}

int Employee::getId() const {
    return id;
}

void Employee::setId(int newId) {
    bool IDisOccupied =
            Employee::occupiedIDs.find(newId) != Employee::occupiedIDs.end();
    if (!IDisOccupied && newId >= 0) {
        this->id = newId;
        Employee::occupiedIDs.insert(newId);
    } else {
        if (IDisOccupied) {
            std::cerr << "Error in employee " << getName()
                      << ": duplicated employee ID" << std::endl;
        } else {
            std::cerr << "Error in employee " << getName()
                      << ": employee ID mustn't be negative" << std::endl;
        }
    }
}

void Employee::setWorkTime(size_t newWorkTime) {
    this->worktime = newWorkTime;
}

bool Employee::isNameCorrect(const std::string &str) {
    if (str.length() > 34 || str.empty()) {
        return false;
    }
    bool isUpperCaseLetter = false;
    bool isLowerCaseLetter = false;
    bool isHyphen = false;
    for (char strChar : str) {
        isUpperCaseLetter = strChar >= 'A' && strChar <= 'Z';
        isLowerCaseLetter = strChar >= 'a' && strChar <= 'z';
        isHyphen = (strChar == '-');
        if (!(isUpperCaseLetter || isLowerCaseLetter || isHyphen)) {
            return false;
        }
    }

    return true;
}

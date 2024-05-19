#define BONUS_FOR_FOUND_BUG 500
#define TESTER_PROJECT_PART 0.05

#include "../include/Tester.h"
#include "../include/Exception.h"

Tester::Tester(
        int id,
        const std::string& name,
        int hourlyRate,
        Project* project,
        int bugsFound
) : Engineer(id, name, Position::TESTER, hourlyRate, project) {
    setBugsFound(bugsFound);
}

Tester::Tester(
        int id,
        const std::string& name,
        int hourlyRate,
        int worktime,
        Project* project,
        int bugsFound
) : Engineer(id, name, Position::TESTER, hourlyRate, worktime, project) {
    setBugsFound(bugsFound);
}

void Tester::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Hourly rate: " << getHourlyRate() << std::endl;
    std::cout << " Bugs found: " << getBugsFound() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
    if (getProject() != nullptr) {
        std::cout << " Project: " << std::endl;
        getProject()->printProjectInfo();
    }
}

int Tester::getBugsFound() const {
    return bugsFound;
}

void Tester::setBugsFound(int newBugsFound) {
    if (newBugsFound < 0) {
        throw InvalidFoundBugsValueException(
                "Value of found bugs can not be negative!");
    }
    this->bugsFound = newBugsFound;
}

void Tester::incrementBugsFound() {
    this->bugsFound += 1;
}

int Tester::calculateProAdditions() const {
    return getBugsFound() * BONUS_FOR_FOUND_BUG;
}

void Tester::calculatePayment() {
    if (getProject() != nullptr) {
        setPayment(calculateBase()
                   + calculateProAdditions()
                   + calculateBudgetPart(getProject()->getBudget(), TESTER_PROJECT_PART));
    } else {
        setPayment(calculateBase()
                   + calculateProAdditions());
    }
}

int Tester::calculateBonus() const {
    return 0;
}

Tester::~Tester() {
    this->bugsFound = -1;
}

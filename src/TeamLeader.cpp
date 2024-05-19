#define TEAM_LEADER_BONUS_FOR_EMPLOYEE 350
#define TEAM_LEADER_PROJECT_PART 0.2

#include "../include/TeamLeader.h"

TeamLeader::TeamLeader(
        int id,
        const std::string& name,
        int hourlyRate,
        Project* project,
        int codeLinesWritten
) : Programmer(id, name, hourlyRate, project, codeLinesWritten) {
    setPosition(Position::TEAM_LEADER);
}

TeamLeader::TeamLeader(
        int id,
        const std::string& name,
        int hourlyRate,
        int worktime,
        Project* project,
        int codeLinesWritten
) : Programmer(id, name, hourlyRate, worktime, project, codeLinesWritten) {
    setPosition(Position::TEAM_LEADER);
}

int TeamLeader::calculateHeads() const {
    if (this->getProject() == nullptr) {
        return 0;
    }

    int numberOfEmployeesInProject = this->getProject()->getNumberOfEmployees() - 1;

    return numberOfEmployeesInProject * TEAM_LEADER_BONUS_FOR_EMPLOYEE;
}

void TeamLeader::calculatePayment() {
    if (getProject() != nullptr) {
        setPayment(calculateBase()
                   + calculateBudgetPart(getProject()->getBudget(), TEAM_LEADER_PROJECT_PART)
                   + calculateHeads()
                   + calculateBonus());
    } else {
        setPayment(calculateBase()
                   + calculateBonus());
    }
}

void TeamLeader::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Hourly rate: " << getHourlyRate() << std::endl;
    std::cout << " Code lines written: " << getCodeLinesWritten() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
    if (getProject() != nullptr) {
        std::cout << " Project: " << std::endl;
        getProject()->printProjectInfo();
    }
}



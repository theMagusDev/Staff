#define TEAM_LEADER_BONUS_FOR_EMPLOYEE 350
#define TEAM_LEADER_PROJECT_PART 0.2

#include "../include/TeamLeader.h"

TeamLeader::TeamLeader(
        int id,
        const std::string& name,
        int hourlyRate,
        Project* project,
        int codeLinesWritten
) : Programmer(id, name, hourlyRate, project, codeLinesWritten) {}

TeamLeader::TeamLeader(
        int id,
        const std::string& name,
        int hourlyRate,
        int worktime,
        Project* project,
        int codeLinesWritten
) : Programmer(id, name, hourlyRate, worktime, project, codeLinesWritten) {}

int TeamLeader::calculateHeads() const {
    if (this->getProject() == nullptr) {
        return 0;
    }

    int numberOfEmployeesInProject = this->getProject()->getNumberOfEmployees() - 1;

    return numberOfEmployeesInProject * TEAM_LEADER_BONUS_FOR_EMPLOYEE;
}

void TeamLeader::calculatePayment() {
    setPayment(calculateBase()
               + calculateProAdditions()
               + calculateBudgetPart(getProject(), TEAM_LEADER_PROJECT_PART)
               + calculateHeads());
}



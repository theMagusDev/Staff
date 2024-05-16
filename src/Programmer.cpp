#define BONUS_FOR_CODE_LINE 100
#define PROGRAMMER_PROJECT_PART 0.2

#include "../include/Programmer.h"
#include "../include/Exception.h"

Programmer::Programmer(
        int id,
        const std::string& name,
        int hourlyRate,
        Project* project,
        int codeLinesWritten
) : Engineer(id, name, Position::PROGRAMMER, hourlyRate, project) {
    setCodeLinesWritten(codeLinesWritten);
}

Programmer::Programmer(
        int id,
        const std::string& name,
        int hourlyRate,
        int worktime,
        Project* project,
        int codeLinesWritten
) : Engineer(id, name, Position::PROGRAMMER, hourlyRate, worktime, project) {
    setCodeLinesWritten(codeLinesWritten);
}

void Programmer::printInfo() {
    std::cout << "Employee " << getName() << " info: " << std::endl;
    std::cout << " ID: " << getId() << std::endl;
    std::cout << " Position: " << getPosition() << std::endl;
    std::cout << " Work time: " << getWorkTime() << std::endl;
    std::cout << " Hourly rate: " << getHourlyRate() << std::endl;
    std::cout << " Code lines written: " << getCodeLinesWritten() << std::endl;
    std::cout << " Payment: " << getPayment() << std::endl;
}

int Programmer::getCodeLinesWritten() const {
    return codeLinesWritten;
}

void Programmer::setCodeLinesWritten(int newCodeLinesWritten) {
    if (newCodeLinesWritten < 0) {
        throw InvalidCodeLinesWrittenValueException(
                "Value of code lines written can not be negative!");
    }
    this->codeLinesWritten = newCodeLinesWritten;
}

void Programmer::incrementCodeLinesWritten() {
    this->codeLinesWritten += 1;
}

int Programmer::calculateProAdditions() const {
    return getCodeLinesWritten() * BONUS_FOR_CODE_LINE;
}

void Programmer::calculatePayment() {
    setPayment(calculateBase()
               + calculateProAdditions()
               + calculateBudgetPart(getProject(), PROGRAMMER_PROJECT_PART));
}

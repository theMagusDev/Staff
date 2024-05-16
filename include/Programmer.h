#ifndef STAFF_PROGRAMMER_H
#define STAFF_PROGRAMMER_H

#include "Engineer.h"

class Programmer : public Engineer {
 public:
    Programmer(int id, const std::string& name, int hourlyRate, Project* project, int codeLinesWritten = 0);
    Programmer(int id, const std::string& name, int hourlyRate, int worktime, Project* project, int codeLinesWritten = 0);

    int getCodeLinesWritten() const;
    void setCodeLinesWritten(int codeLinesWritten);
    void incrementCodeLinesWritten();

    void calculatePayment() override;
    void printInfo() override;

 protected:
    int calculateProAdditions() const override;

 private:
    int codeLinesWritten;
};


#endif //STAFF_PROGRAMMER_H

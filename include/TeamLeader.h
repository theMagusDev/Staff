#ifndef STAFF_TEAMLEADER_H
#define STAFF_TEAMLEADER_H

#include "Heading.h"
#include "Programmer.h"

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, const std::string& name, int hourlyRate, Project* project, int codeLinesWritten = 0);
    TeamLeader(int id, const std::string& name, int hourlyRate, int worktime, Project* project, int codeLinesWritten = 0);

    void calculatePayment() override;
    void printInfo() override;
 private:
    int calculateHeads() const override;
};


#endif //STAFF_TEAMLEADER_H

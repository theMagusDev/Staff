#ifndef STAFF_ENGINEER_H
#define STAFF_ENGINEER_H

#include "Personal.h"
#include "Project.h"
#include "ProjectBudget.h"

class Engineer : public Personal, public ProjectBudget {
 public:
    Engineer(
        int id,
        const std::string& name,
        Position position,
        int hourlyRate,
        Project* project
    );
    Engineer(
            int id,
            const std::string& name,
            Position position,
            int hourlyRate,
            int worktime,
            Project* project
    );
    ~Engineer() override;

    Project *getProject() const;
    void setProject(Project *project);

    void calculatePayment() override;

 private:
    Project* project;
};


#endif // STAFF_ENGINEER_H

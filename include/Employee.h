#ifndef STAFF_EMPLOYEE_H
#define STAFF_EMPLOYEE_H

#include <string>
#include <set>

enum class Position {
    UNINITIALIZED,
    TEAM_LEADER,
    PROGRAMMER,
    TESTER,
    PROJECT_MANAGER,
    SENIOR_MANAGER,
    DRIVER,
    CLEANER
};

class Employee {
 public:
    Employee(int id, const std::string& name, Position& position);
    Employee(int id, const std::string &name, Position& position, int worktime);
    Employee(int id, const std::string &name, int worktime = 0);
    ~Employee();

    int getId() const;
    void setId(int id);
    const std::string& getName() const;
    void setName(const std::string& newName);
    const std::string& getPosition() const;
    void setPosition(Position position);
    int getPayment(bool calculateAutomatically = true);
    void setPayment(int payment);
    int getWorkTime() const;
    void setWorkTime(int newWorkTime);

    virtual void calculatePayment() = 0;
    virtual void printInfo() = 0;

 private:
    int id;
    std::string name;
    Position position;
    int worktime; // counted in days
    int payment;

    static std::set<int> occupiedIDs;
    static bool isNameCorrect(const std::string& str);
};


#endif  // STAFF_EMPLOYEE_H

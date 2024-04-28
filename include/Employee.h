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
    Employee(int id, const std::string& name, Position position);
    Employee(int id, const std::string &name, Position position, size_t worktime);
    ~Employee();

    int getId() const;
    void setId(int id);
    const std::string& getName() const;
    void setName(const std::string& newName);
    Position getPosition() const;
    void setPosition(Position position);
    int getPayment() const;
    void setPayment(int payment);
    void setWorkTime(size_t newWorkTime);

private:
    int id;
    std::string name;
    Position position;
    size_t worktime;
    int payment;

    std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::duration<double>
    > joinDate;
    static std::set<int> occupiedIDs;
    static bool isNameCorrect(const std::string& str);
};


#endif  // STAFF_EMPLOYEE_H

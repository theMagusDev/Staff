#ifndef STAFF_EXCEPTION_H
#define STAFF_EXCEPTION_H

#include <string>
#include <exception>
#include <utility>

class CustomException : std::exception {
 public:
    explicit CustomException(std::string message);
    const char* what() const noexcept override {
        return message.c_str();
    }

 private:
    std::string message;
};

class EmployeeException : public CustomException {
 public:
    explicit EmployeeException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidNameException : public EmployeeException {
 public:
    explicit InvalidNameException(std::string message) :
            EmployeeException(std::move(message)) {}
};
class InvalidEmployeeIDException : public EmployeeException {
public:
    explicit InvalidEmployeeIDException(std::string message) :
            EmployeeException(std::move(message)) {}
};
class InvalidWorktimeException : public EmployeeException {
 public:
    explicit InvalidWorktimeException(std::string message) :
            EmployeeException(std::move(message)) {}
};

class ProjectException : public CustomException {
 public:
    explicit ProjectException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidProjectIDException : public ProjectException {
 public:
    explicit InvalidProjectIDException(std::string message) :
            ProjectException(std::move(message)) {}
};
class InvalidProjectBudgetException : public ProjectException {
 public:
    explicit InvalidProjectBudgetException(std::string message) :
        ProjectException(std::move(message)) {}
};
class InvalidNumberOfEmployeesException : public ProjectException {
 public:
    explicit InvalidNumberOfEmployeesException(std::string message) :
        ProjectException(std::move(message)) {}
};

class PersonalException : public CustomException {
 public:
    explicit PersonalException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidHourlyRateException : public PersonalException {
 public:
    explicit InvalidHourlyRateException(std::string message) :
            PersonalException(std::move(message)) {};
};

class DriverException : public PersonalException {
 public:
    explicit DriverException(std::string message) :
            PersonalException(std::move(message)) {}
};
class InvalidNightHoursException : public DriverException {
 public:
    explicit InvalidNightHoursException(std::string message) :
            DriverException(std::move(message)) {}
};

class EngineerException : public PersonalException {
 public:
    explicit EngineerException(std::string message) :
            PersonalException(std::move(message)) {}
};
class TesterException : public EngineerException {
public:
    explicit TesterException(std::string message) :
            EngineerException(std::move(message)) {}
};
class InvalidFoundBugsValueException : public TesterException {
public:
    explicit InvalidFoundBugsValueException(std::string message) :
            TesterException(std::move(message)) {};
};

#endif //STAFF_EXCEPTION_H

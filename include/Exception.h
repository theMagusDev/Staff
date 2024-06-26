#ifndef STAFF_EXCEPTION_H
#define STAFF_EXCEPTION_H

#include <string>
#include <exception>
#include <utility>

class CustomException : std::exception {
 public:
    explicit CustomException(const char* message);
    const char* what() const noexcept override {
        return message.c_str();
    }

 private:
    std::string message;
};

class EmployeeException : public CustomException {
 public:
    explicit EmployeeException(const char* message) :
            CustomException(message) {}
};
class InvalidNameException : public EmployeeException {
 public:
    explicit InvalidNameException(const char* message) :
            EmployeeException(message) {}
};
class InvalidEmployeeIDException : public EmployeeException {
public:
    explicit InvalidEmployeeIDException(const char* message) :
            EmployeeException(message) {}
};
class InvalidWorktimeException : public EmployeeException {
 public:
    explicit InvalidWorktimeException(const char* message) :
            EmployeeException(message) {}
};

class ProjectException : public CustomException {
 public:
    explicit ProjectException(const char* message) :
            CustomException(message) {}
};
class InvalidProjectIDException : public ProjectException {
 public:
    explicit InvalidProjectIDException(const char* message) :
            ProjectException(message) {}
};
class InvalidProjectBudgetException : public ProjectException {
 public:
    explicit InvalidProjectBudgetException(const char* message) :
        ProjectException(message) {}
};
class InvalidNumberOfEmployeesException : public ProjectException {
 public:
    explicit InvalidNumberOfEmployeesException(const char* message) :
        ProjectException(message) {}
};
class InvalidProjectManagerIDException : public ProjectException {
 public:
    explicit InvalidProjectManagerIDException(const char* message) :
            ProjectException(message) {}
};

class PersonalException : public CustomException {
 public:
    explicit PersonalException(const char* message) :
            CustomException(message) {}
};
class InvalidHourlyRateException : public PersonalException {
 public:
    explicit InvalidHourlyRateException(const char* message) :
            PersonalException(message) {};
};

class DriverException : public PersonalException {
 public:
    explicit DriverException(const char* message) :
            PersonalException(message) {}
};
class InvalidNightHoursException : public DriverException {
 public:
    explicit InvalidNightHoursException(const char* message) :
            DriverException(message) {}
};

class EngineerException : public PersonalException {
 public:
    explicit EngineerException(const char* message) :
            PersonalException(message) {}
};
class TesterException : public EngineerException {
 public:
    explicit TesterException(const char* message) :
            EngineerException(message) {}
};
class InvalidFoundBugsValueException : public TesterException {
 public:
    explicit InvalidFoundBugsValueException(const char* message) :
            TesterException(message) {};
};

class ProgrammerException : public EngineerException {
 public:
    explicit ProgrammerException(const char* message) :
            EngineerException(message) {}
};
class InvalidCodeLinesWrittenValueException : public ProgrammerException {
 public:
    explicit InvalidCodeLinesWrittenValueException(const char* message) :
            ProgrammerException(message) {};
};

class FileIOException : public CustomException {
 public:
    explicit FileIOException(const char* message) :
            CustomException(message) {};
};

#endif //STAFF_EXCEPTION_H

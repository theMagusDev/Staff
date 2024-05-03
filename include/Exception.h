#ifndef STAFF_EXCEPTION_H
#define STAFF_EXCEPTION_H

#include <string>
#include <exception>
#include <utility>

class CustomException : std::exception {
 public:
    explicit CustomException(std::string message);
    std::string getMessage() const;

 private:
    std::string message;
};

class EmployeeException: public CustomException {
 public:
    explicit EmployeeException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidNameException: public EmployeeException {
 public:
    explicit InvalidNameException(std::string message) :
            EmployeeException(std::move(message)) {}
};
class InvalidEmployeeIDException: public EmployeeException {
public:
    explicit InvalidEmployeeIDException(std::string message) :
            EmployeeException(std::move(message)) {}
};
class InvalidWorktimeException: public EmployeeException {
 public:
    explicit InvalidWorktimeException(std::string message) :
            EmployeeException(std::move(message)) {}
};

class ProjectException: public CustomException {
 public:
    explicit ProjectException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidProjectIDException: public EmployeeException {
 public:
    explicit InvalidProjectIDException(std::string message) :
            EmployeeException(std::move(message)) {}
};

class PersonalException: public CustomException {
 public:
    explicit PersonalException(std::string message) :
            CustomException(std::move(message)) {}
};
class InvalidSalaryException: public PersonalException {
public:
    explicit InvalidSalaryException(std::string message) :
            PersonalException(std::move(message)) {}
};

#endif //STAFF_EXCEPTION_H

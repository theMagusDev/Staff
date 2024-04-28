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

#endif //STAFF_EXCEPTION_H

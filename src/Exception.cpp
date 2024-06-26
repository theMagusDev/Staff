#include "../include/Exception.h"

CustomException::CustomException(const char* message) {
    this->message = std::string(message);
}


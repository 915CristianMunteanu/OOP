#pragma once
#include "UserService.h"
class ValidationException : public std::exception {
private:
    std::string message;
public:
    explicit ValidationException(std::string& _message);

    const char* what() const noexcept override;
};
class Validator {
public:
    Validator();
    void validate_year(string& year);
    void validate_number(string& number);
    void validate_year_int(int year);
    void validate_number_int(int number);
};
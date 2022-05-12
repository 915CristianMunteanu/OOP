#include "Validators.h"
ValidationException::ValidationException(std::string& _message):message(_message)
{
}

const char* ValidationException::what() const noexcept
{
	return message.c_str();
}

Validator::Validator()
{
}

void Validator::validate_year(string& year)
{
    std::string errors;
    if (year.empty())
        errors += std::string("The year input is empty!");
    if (year.find_first_not_of("0123456789") != std::string::npos)
        errors += std::string("The year input has non-digit characters!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void Validator::validate_number(string& number)
{
    std::string errors;
    if (number.empty())
        errors += std::string("The number of likes input is empty!");
    if (number.find_first_not_of("0123456789") != std::string::npos)
        errors += std::string("The number of likes input has non-digit characters!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void Validator::validate_year_int(int year)
{
    std::string errors;
    if (year < 1500 || year>2022)
        errors += string("The year is not right!");
    if (!errors.empty())
            throw ValidationException(errors);
        
}

void Validator::validate_number_int(int number)
{
    std::string errors;
    if (number < 0)
        errors += string("The number of likes is not right!");
    if (!errors.empty())
        throw ValidationException(errors);
}

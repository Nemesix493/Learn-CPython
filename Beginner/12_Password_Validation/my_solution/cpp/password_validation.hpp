#ifndef PASSWORD_VALIDATION
#define PASSWORD_VALIDATION
#include <string>

bool passwordValidation(std::string passwordToCheck);

bool containUpperCase(std::string passwordToCheck);

bool containLowerCase(std::string passwordToCheck);

bool containNumber(std::string passwordToCheck);

bool containSpecial(std::string passwordToCheck);

#endif
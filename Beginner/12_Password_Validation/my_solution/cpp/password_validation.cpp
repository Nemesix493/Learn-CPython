#include "password_validation.hpp"

bool passwordValidation(std::string passwordToCheck){
    return (
        passwordToCheck.length() >= 8 &&
        containLowerCase(passwordToCheck) &&
        containNumber(passwordToCheck) &&
        containUpperCase(passwordToCheck) &&
        containSpecial(passwordToCheck)
    );
}

bool containUpperCase(std::string passwordToCheck){
    for(int i = 0; i < passwordToCheck.length(); i++){
        char testedChar = passwordToCheck[i];
        if(testedChar>=65 && testedChar<=90){
            return true;
        }
    }
    return false;
}

bool containLowerCase(std::string passwordToCheck){
    for(int i = 0; i < passwordToCheck.length(); i++){
        char testedChar = passwordToCheck[i];
        if(testedChar>=97 && testedChar<=122){
            return true;
        }
    }
    return false;
}

bool containNumber(std::string passwordToCheck){
    for(int i = 0; i < passwordToCheck.length(); i++){
        char testedChar = passwordToCheck[i];
        if(testedChar>=48 && testedChar<=57){
            return true;
        }
    }
    return false;
}

bool containSpecial(std::string passwordToCheck){
    for(int i = 0; i < passwordToCheck.length(); i++){
        char testedChar = passwordToCheck[i];
        if(
            !(testedChar>=48 && testedChar<=57) &&
            !(testedChar>=65 && testedChar<=90) &&
            !(testedChar>=97 && testedChar<=122)
        ){
            return true;
        }
    }
    return false;
}

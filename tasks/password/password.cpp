#include "password.h"
#include <cctype>

bool ValidatePassword(const std::string& password) {
    int lower = 0;
    int supper = 0;
    int digit = 0;
    int other = 0;
    if (size(password) > 14 || size(password) < 8) {
        return false;
    }
    for (int i = 0; i < size(password); ++i) {
        if (islower(password[i])) {
            lower = 1;
        }
        if (isupper(password[i])) {
            supper = 1;
        }
        if (isdigit(password[i])) {
            digit = 1;
        }
        if (ispunct(password[i])) {
            other = 1;
        }
        if (password[i] > 126 || password[i] < 33) {
            return false;
        }
    }
    if (lower + supper + digit + other < 3) {
        return false;
    }
    return true;
}
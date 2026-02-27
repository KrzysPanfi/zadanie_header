#ifndef ZAD1_H
#define ZAD1_H

#include <algorithm>
#include <iostream>
#include <string>

namespace zad1 {


    std::string removeSpaces(std::string str) {
        std::erase(str,' ');
        return str;
    }


    bool isPalindrome(std::string str) {
        std::string str1 = removeSpaces(str);
        int left = 0, right = str1.size() - 1;
        while (left < right) {
            if (tolower(str1[left]) != tolower(str1[right])) { // Dodany tolower dla lepszego testu
                return false;
            }
            left++;
            right--;
        }
        return true;
    }


    void uruchomZadanie() {
        std::string test = "koby la ma maly bok";
        std::cout << "Test palindromu: '" << test << "' -> "
                  << (isPalindrome(test) ? "TAK" : "NIE") << std::endl;
    }
}

#endif

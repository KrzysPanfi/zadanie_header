
#include <iostream>
// Twoja funkcja pomocnicza
std::string removeSpaces(std::string str) {
    std::erase(str,' ');
    return str;
}

// Twoja funkcja logiczna
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

// Funkcja wywoływana w main
void uruchomZadanie() {
    std::string test = "koby la ma maly bok";
    std::cout << "Test palindromu: '" << test << "' -> "
              << (isPalindrome(test) ? "TAK" : "NIE") << std::endl;
}


#ifndef ZAD2_H
#define ZAD2_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

namespace zad2 {

    inline std::vector<int> modify(std::vector<int> vec, const std::string &command) {
        std::vector<int> result = vec;
        if (command == "append") {
            result.push_back(18);
        } else if (command == "truncate") {
            if (result.size() > 2) {
                result.pop_back();
                result.erase(result.begin());
            }
        } else if (command == "reverse") {
            std::ranges::reverse(result); // Uproszczone do modyfikacji w miejscu
        }
        return result;
    }

    inline int max_nested_parentheses_depth(const std::string &word) {
        int count = 0;
        int max_depth = 0;
        for (auto c: word) {
            if (c == '(') {
                count++;
                if (count > max_depth) max_depth = count;
            } else if (c == ')') {
                count--;
            }
        }
        return max_depth;
    }

    inline bool correctparenthesses(const std::string &word) {
        std::vector<char> stack;
        for (auto c : word) {
            if (c == '(' || c == '{' || c == '[' || c == '<') {
                stack.push_back(c);
            } else {
                if (stack.empty()) return false;
                char last = stack.back();
                if ((c == ')' && last == '(') || (c == '}' && last == '{') ||
                    (c == ']' && last == '[') || (c == '>' && last == '<')) {
                    stack.pop_back();
                } else return false;
            }
        }
        return stack.empty();
    }

    inline void box_print(const std::vector<std::string> &words) {
        if (words.empty()) return;
        size_t max_length = 0;
        for (const auto &word: words) max_length = std::max(max_length, word.length());
        
        std::string frame(max_length + 2, '*');
        std::cout << frame << std::endl;
        for (const auto &word: words) {
            std::cout << "*" << word << std::string(max_length - word.length(), ' ') << "*" << std::endl;
        }
        std::cout << frame << std::endl;
    }

    inline int count_chars(const std::string &str, char chr) {
        return std::count(str.begin(), str.end(), chr);
    }

    inline int dotproduct(const std::vector<int> &v1, const std::vector<int> &v2) {
        int res = 0;
        for (size_t i = 0; i < std::min(v1.size(), v2.size()); i++) res += v1[i] * v2[i];
        return res;
    }


    void uruchomZadanie() {
        auto words = std::vector<std::string>{"Hello", "ALO", "in", "quite", "a", "wide", "frame"};
        box_print(words);
        std::cout << "Nawiasy <({})>: " << (correctparenthesses("<({})>") ? "OK" : "Bład") << std::endl;
        std::cout << "Iloczyn skalarny: " << dotproduct({2, 2}, {3, 4}) << std::endl;
    }
}

#endif
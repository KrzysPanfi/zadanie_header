//
// Created by l0860 on 26.02.2026.
//

#ifndef UNTITLED2_ZAD3_H
#define UNTITLED2_ZAD3_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

namespace zad3 {
    enum class ordering {
        required,
        not_required
    };

    template <typename T>
    bool contains(const std::vector<T>& source, const std::vector<T>& subset, ordering opt) {
        if (subset.empty()) return false;

        if (opt == ordering::required) {
            return std::search(source.begin(), source.end(),
                subset.begin(), subset.end()) != source.end();
        }
        else {
            std::unordered_set<T> source_set(source.begin(), source.end());
            for (const auto& item : subset) {
                if (source_set.find(item) == source_set.end()) {
                    return false;
                }
            }
            return true;
        }
    }

    int count_long_words(const std::vector<std::string>& words, int min_length) {
        int count = 0;

        for (const std::string& word : words) {
            if (word.length() >=min_length) {
                count++;
            }
        }
        return count;
    }
    bool are_the_same() {
        auto v = std::vector<int>();
        for (int i = 0;i < 8;i++) {
            std:: string a;
            std::getline(std::cin, a);
            int num = std::stoi(a);
            v.push_back(num);
        }
        std::size_t const half_size = v.size() / 2;
        std::vector<int>v1  (v.begin(), v.begin() + half_size);
        std::vector<int>v2(v.begin()+half_size, v.end());
        std::sort(v1.begin(),v1.end());
        std::sort(v2.begin(), v2.end());
        for (int j = 0;j < v1.size();j++) {
            if (v1[j] != v2[j]) {
                return false;
            }
        }
        return true;
    }

    void print_alphabetically(std::vector<std::string> words) {
        std::sort(words.begin(), words.end());
        for (const std::string& word : words) {
            std::cout << word<<std::endl;
        }
    }
    void uruchomzadanie()
    {
        auto vect = std::vector<std::string>({ "TEST1","TEST2","D" });
        std::cout << count_long_words(vect, 5) << std::endl;
        auto vect1 = std::vector<std::string>({ "ala","czarek","bartek" });
        print_alphabetically(vect1);
        // std::cout << are_the_same() << std::endl;
        auto source = std::vector<std::string>{
            "C++", "may", "seem", "complicated",
          "but",
          "yeah", "it", "kind", "of", "is"
           };
        auto subset1 = std::vector<std::string>{
            "C++", "may", "seem"
                };
        auto subset2 = std::vector<std::string>{
            "C++", "but", "complicated"
            };
        auto subset3 = std::vector<std::string>{
            "C++", "is", "easy"
           };
        std::cout << contains(source, subset1, ordering::required)
             << '\n'
             << contains(source, subset1, ordering::not_required)
             << '\n'
             << contains(source, subset2, ordering::required)
             << '\n'
             << contains(source, subset2, ordering::not_required)
             << '\n'
             << contains(source, subset3, ordering::required)
             << '\n'
             << contains(source, subset3, ordering::not_required);
    };
}

#endif //UNTITLED2_ZAD3_H
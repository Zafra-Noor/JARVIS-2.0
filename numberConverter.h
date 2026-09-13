#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> wordsToNumbers = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}
};

int wordToNumber(const string& word) {
    auto it = wordsToNumbers.find(word);
    return (it != wordsToNumbers.end()) ? it->second : -1;
}

int parseNumber(const string& input) {
    istringstream iss(input);
    string word;
    int result = 0;
    int current = 0;

    while (iss >> word) {
        // Remove hyphens and "and"
        word.erase(remove(word.begin(), word.end(), '-'), word.end());
        if (word == "and") continue;

        int number = wordToNumber(word);

        if (number == 100) {
            current *= 100;
        } else if (number == 1000) {
            current *= 1000;
            result += current;
            current = 0;
        } else if (number != -1) {
            current += number;
        }
    }
    result += current;
    return result;
}
/**
 * @file utilities.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines some helper functions
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <random>
#include <chrono>
#include <algorithm>

namespace Utilities {
    static std::random_device rd; // default seed
    static std::mt19937 gen{rd()};

    inline int randInt(int min, int max) {
        std::uniform_int_distribution<std::mt19937::result_type> r(min, max);
        return r(gen);
    }

    inline float randf() {
        std::uniform_real_distribution<float> r(0, 1);
        return r(gen);
    }

    inline std::string trim(std::string str) {
        const auto begin = str.find_first_not_of(' ');
        if (begin == std::string::npos) {
            return "";
        }
        const auto end = str.find_last_not_of(' ');
        const auto range = end - begin + 1;

        return str.substr(begin, range);
    }

    inline bool isNat(std::string str) {
        int integer = 0;
        try {
            integer = std::stoi(str);
        } catch (...) {
            return false;
        }
        if (integer >= 0) {
            return true;
        } else {
            return false;
        }
    }

    inline bool toBool(std::string value) {
        if (value == "TRUE") {
            return true;
        }
        return false;
    }
}

#endif

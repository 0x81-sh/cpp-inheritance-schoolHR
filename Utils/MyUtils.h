#pragma once
#include <string>
#include <sstream>

class MyUtils {
    public:
        // "universal" version of the type to string converter
        template <typename T> static std::string toString(T value) {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }
};




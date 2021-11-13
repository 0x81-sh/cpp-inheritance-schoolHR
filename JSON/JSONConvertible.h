#pragma once
#include <string>
#include "Map.h"

// A sort of "base class" or interface from which other class can extend from
// Provides the foundation for converting to JSON

class JSONConvertible {
    protected:
        virtual Map& convert(Map &ref) const;
        JSONConvertible();
    public:
        std::string toJSON() const;
};




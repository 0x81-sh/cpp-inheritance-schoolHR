#include "JSONConvertible.h"

// Do nothing as the class is essentially abstract
JSONConvertible::JSONConvertible() {}

Map& JSONConvertible::convert(Map &ref) const {
    return ref;
}

std::string JSONConvertible::toJSON() const {
    Map x;
    convert(x);

    return x.toJSON();
}



#include "Pupil.h"

Pupil::Pupil(const std::string &firstName, const std::string &lastName, int socSecNum, const Date &dateOfBirth, const std::string &className)
    : Person(firstName, lastName, socSecNum, dateOfBirth), className(className) {}

const std::string &Pupil::getClassName() const {
    return className;
}

void Pupil::setClassName(const std::string &className) {
    Pupil::className = className;
}

Map &Pupil::convert(Map &ref) const {
    Person::convert(ref);
    ref.addElement("className", "\"" + className + "\"");

    return ref;
}

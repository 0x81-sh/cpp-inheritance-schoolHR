#include "Teacher.h"

Teacher::Teacher(const std::string &firstName, const std::string &lastName, int socSecNum, const Date& dateOfBirth, int employeeNum)
    : Person(firstName, lastName, socSecNum, dateOfBirth), employeeNum(employeeNum) {}

int Teacher::getEmployeeNum() const {
    return employeeNum;
}

void Teacher::setEmployeeNum(int employeeNum) {
    Teacher::employeeNum = employeeNum;
}

Map &Teacher::convert(Map &ref) const {
    Person::convert(ref);
    ref.addElement("employeeNum", MyUtils::toString<int>(employeeNum));

    return ref;
}

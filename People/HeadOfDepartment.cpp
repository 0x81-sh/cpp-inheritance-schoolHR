#include "HeadOfDepartment.h"

HeadOfDepartment::HeadOfDepartment(const std::string &firstName, const std::string &lastName, int socSecNum, const Date& dateOfBirth, int employeeNum, const std::string &departmentName)
    : Teacher(firstName, lastName, socSecNum, dateOfBirth, employeeNum), departmentName(departmentName) {}

const std::string &HeadOfDepartment::getDepartmentName() const {
    return departmentName;
}

void HeadOfDepartment::setDepartmentName(const std::string &departmentName) {
    HeadOfDepartment::departmentName = departmentName;
}

Map &HeadOfDepartment::convert(Map &ref) const {
    Teacher::convert(ref);
    ref.addElement("departmentName", "\"" + departmentName + "\"");

    return ref;
}


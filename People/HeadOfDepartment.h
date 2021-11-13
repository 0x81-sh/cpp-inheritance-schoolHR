#pragma once
#include "Teacher.h"

class HeadOfDepartment : public Teacher {
    private:
        std::string departmentName;
    protected:
        Map& convert(Map &ref) const override;
    public:
        HeadOfDepartment(const std::string &firstName = "", const std::string &lastName = "", int socSecNum = 0, const Date& dateOfBirth = {1, 1, 2000}, int employeeNum = 0, const std::string &departmentName = "");

        const std::string &getDepartmentName() const;
        void setDepartmentName(const std::string &departmentName);
};




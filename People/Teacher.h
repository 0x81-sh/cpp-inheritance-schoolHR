#pragma once
#include "Person.h"

class Teacher : public Person {
    private:
        int employeeNum;
    protected:
        Map& convert(Map &ref) const override;
    public:
        Teacher(const std::string &firstName = "", const std::string &lastName = "", int socSecNum = 0, const Date& dateOfBirth = {1, 1, 2000}, int employeeNum = 0);

        int getEmployeeNum() const;
        void setEmployeeNum(int employeeNum);
};




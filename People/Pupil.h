#pragma once
#include "Person.h"

class Pupil : public Person {
    private:
        std::string className;
    protected:
        Map& convert(Map &ref) const override;
    public:
        Pupil(const std::string &firstName = "", const std::string &lastName = "", int socSecNum = 0, const Date &dateOfBirth = {1, 1, 2000}, const std::string &className = "");

        const std::string &getClassName() const;
        void setClassName(const std::string &className);
};




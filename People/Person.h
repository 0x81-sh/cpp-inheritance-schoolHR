#pragma once
#include <string>
#include <sstream>
#include "../JSON/JSONConvertible.h"
#include "../Date/Date.h"

class Person : public JSONConvertible {
    private:
        std::string firstName;
        std::string lastName;
        int socSecNum;
        Date dateOfBirth;
    protected:
        Map& convert(Map &ref) const override;
    public:
        Person(const std::string &firstName = "", const std::string &lastName = "", int socSecNum = 0, const Date& dateOfBirth = {1, 1, 2000});

        const std::string &getFirstName() const;
        void setFirstName(const std::string &firstName);
        const std::string &getLastName() const;
        void setLastName(const std::string &lastName);
        int getSocSecNum() const;
        void setSocSecNum(int socSecNum);
        const Date &getDateOfBirth() const;
        void setDateOfBirth(const Date &dateOfBirth);
};




#include "Person.h"

Person::Person(const std::string &firstName, const std::string &lastName, int socSecNum, const Date& dateOfBirth)
    : firstName(firstName), lastName(lastName), socSecNum(socSecNum), dateOfBirth(dateOfBirth) {}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

int Person::getSocSecNum() const {
    return socSecNum;
}

void Person::setSocSecNum(int socSecNum) {
    Person::socSecNum = socSecNum;
}

const Date &Person::getDateOfBirth() const {
    return dateOfBirth;
}

void Person::setDateOfBirth(const Date &dateOfBirth) {
    Person::dateOfBirth = dateOfBirth;
}

Map &Person::convert(Map &ref) const {
    JSONConvertible::convert(ref);

    Map personalDetails;
    personalDetails.addElement("firstName", "\"" + firstName + "\"");
    personalDetails.addElement("lastName", "\"" + lastName + "\"");
    personalDetails.addElement("socSecNum", MyUtils::toString<int>(socSecNum));

    ref.addElement("dateOfBirth", dateOfBirth.toMap());
    ref.addElement("personalDetails", personalDetails);

    return ref;
}

#include "Date.h"

Map& Date::convert(Map &ref) const {
    ref.addElement("day", MyUtils::toString<int>(day));
    ref.addElement("month", MyUtils::toString<int>(month));
    ref.addElement("year", MyUtils::toString<int>(year));

    return ref;
}

Date::Date(int day, int month, int year) : year(year) {
    if (day > 31) this->day = 1; else this->day = day;
    if (month > 12) this->month = 1; else this->month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

Map Date::toMap() const {
    Map x;
    return convert(x);
}


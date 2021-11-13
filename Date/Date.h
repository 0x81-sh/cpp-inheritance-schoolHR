#pragma once
#include "../JSON/JSONConvertible.h"
#include "../Utils/MyUtils.h"

class Date : public JSONConvertible {
    private:
        int day;
        int month;
        int year;
    protected:
        Map& convert(Map &ref) const override;
    public:
        Date(int day, int month, int year);

        // Provide the map for external use in JSON-conversion
        Map toMap() const;

        int getDay() const;
        void setDay(int day);
        int getMonth() const;
        void setMonth(int month);
        int getYear() const;
        void setYear(int year);

};




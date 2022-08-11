#pragma once
#include <string>
#include <ctime>
#include <stdexcept>
#include "date.h"
#include "time.h"

using namespace std;

namespace datetime {

    class DateTime
    {
    public:
        DateTime(int year, int month, int day, int hours=0, int minute=0, int second=0) : 
            date_(year, month, day), time_(hours, minute, second) {
        }

        const Date& getDate() const {
            return date_;
        }

        const Time& getTime() const {
            return time_;
        }

        DayOfWeek getDayOfWeek() const {
            return date_.getDayOfWeek();
        }

    private:
        Date date_;
        Time time_;
    };
};

#pragma once
#include <string>
#include <ctime>
#include <stdexcept>
using namespace std;

namespace datetime {

    enum class DayOfWeek {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    };

    class Date
    {
    public:
        //Date(2022, -10, 11)
        Date(int year, int month, int day) {
            tm_ = {};
            tm_.tm_year = year - 1900;
            tm_.tm_mon = month - 1;
            tm_.tm_mday = day;

            ::mktime(&tm_);

            if (tm_.tm_mday != day || day < 0) {
                throw invalid_argument("[" + to_string(day) + "] 날짜 범위가 맞지 않습니다.");
            }
            if (tm_.tm_mon != month - 1 || month < 0) {
                throw invalid_argument("[" + to_string(month) + "]  달의 범위가 잘못되었습니다");
            }
            if (tm_.tm_year != year - 1900 || tm_.tm_year < 0) {
                throw invalid_argument("[" + to_string(year) + "] 년도가 범위에 맞지 않습니다.");
            }
        }

        int getYear() const {
            return tm_.tm_year + 1900;
        }
        int getMonth() const {
            return tm_.tm_mon + 1;
        }
        int getDay() const {
            return tm_.tm_mday;
        }

        DayOfWeek  getDayOfWeek() const {
            return static_cast<DayOfWeek>(tm_.tm_wday);
        }

        bool operator == (const Date& r) const {
            return ((this->tm_.tm_year == r.tm_.tm_year) && 
                (this->tm_.tm_mon == r.tm_.tm_mon) && 
                (this->tm_.tm_mday == r.tm_.tm_mday) );
        }

        bool operator > (const Date& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) > (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator > (Date&& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) > (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator >= (const Date& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) >= (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator >= (Date&& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) >= (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator < (const Date& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) < (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator < (Date&& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) < (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator <= (const Date& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) <= (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        bool operator <= (Date&& r) const {
            return ((this->tm_.tm_year * 10000 + this->tm_.tm_mon * 100 + this->tm_.tm_mday) <= (r.tm_.tm_year * 10000 + r.tm_.tm_mon * 100 + r.tm_.tm_mday));
        }

        string getString() const {
            char       result[80];
            strftime(result, sizeof(result), "%Y-%m-%d", &tm_); // YYYY-MM-DD 형태의 스트링
            return string(result);
        }

    private:
    
        tm  tm_;
    };
};
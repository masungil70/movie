#pragma once

#include <ctime>
#include <string>
using namespace std;

namespace datetime {

    class Time {
    public:
        Time(int hour = 0, int minute = 0, int second = 0) :
            hour_(hour), minute_(minute), second_(second) {
        }

        bool operator == (const Time& r) const {
            return getTime() == r.getTime();
        }

        bool operator > (const Time& r) const {
            return getTime() > r.getTime();
        }

        bool operator > (Time&& r) const {
            return getTime() > r.getTime();
        }

        bool operator >= (const Time& r) const {
            return getTime() >= r.getTime();
        }

        bool operator >= (Time&& r) const {
            return getTime() >= r.getTime();
        }

        bool operator < (const Time& r) const {
            return getTime() < r.getTime();
        }

        bool operator < (Time&& r) const {
            return getTime() < r.getTime();
        }

        bool operator <= (const Time& r) const {
            return getTime() <= r.getTime();
        }

        bool operator <= (Time&& r) const {
            return getTime() <= r.getTime();
        }

        string getString() const {
            char result[20];
            sprintf_s(result, sizeof(result), "%02d:%02d", hour_, minute_);
            return string{ result };
        }
    private:
        int getTime() const {
            return (hour_ * 10000 + minute_ * 100 + second_);
        }

        int hour_;
        int minute_;
        int second_;
    };
};

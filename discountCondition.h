#pragma once

#include "screening.h"

enum class DiscountConditionType {
    SEQUENCE,       // 순번 조건
    PERIOD          // 기간 조건
};

class DiscountCondition {
public:
    DiscountCondition(int sequence) : 
        DiscountCondition(DiscountConditionType::SEQUENCE, sequence, DayOfWeek::SUNDAY, 0, 0) {
    }

    DiscountCondition(DayOfWeek dayOfWeek, Time startTime, Time endTime) :
        DiscountCondition(DiscountConditionType::PERIOD, 0, dayOfWeek, startTime, endTime) {
    }

    DiscountCondition(const DiscountCondition& r) :
        type_(r.type_), sequence_(r.sequence_), dayOfWeek_(r.dayOfWeek_), startTime_(r.startTime_), endTime_(r.endTime_) {
    }

    DiscountCondition& operator=(const DiscountCondition& r)  {
        if (this == &r) {
            return *this;
        }

        type_ = r.type_;
        sequence_ = r.sequence_;
        dayOfWeek_ = r.dayOfWeek_;
        startTime_ = r.startTime_;
        endTime_ = r.endTime_;
        return *this;
    }

    //DiscountConditionType getType() const {
    //    return type_;
    //}

    //void setType(DiscountConditionType type) {
    //    type_ = type;
    //}

    //DayOfWeek getDayOfWeek() const {
    //    return dayOfWeek_;
    //}

    //void setDayOfWeek(DayOfWeek dayOfWeek) {
    //    dayOfWeek_ = dayOfWeek;
    //}

    //Time getStartTime() const {
    //    return startTime_;
    //}

    //void setStartTime(Time startTime) {
    //    startTime_ = startTime;
    //}

    //Time getEndTime() const {
    //    return endTime_;
    //}

    //void setEndTime(Time endTime) {
    //    endTime_ = endTime;
    //}

    //int getSequence() const {
    //    return sequence_;
    //}

    //void setSequence(int sequence) {
    //    sequence_ = sequence;
    //}

    //bool isDiscountable(Screening& screening) const {
    //    if (isDiscountablePeriod(screening)) {
    //        return true;
    //    }
    //    else if (isDiscountableSequence(screening)) {
    //        return true;
    //    }
    //    return false;
    //}

    bool isDiscountable(const Screening& screening) const {
        return (isDiscountablePeriod(screening) || isDiscountableSequence(screening));
    }

private:
    bool isDiscountablePeriod(const Screening& screening) const {
        return (type_ == DiscountConditionType::PERIOD &&
            dayOfWeek_ == screening.getWhenScreened().getDayOfWeek() &&
            startTime_ <= screening.getWhenScreened().getTime() &&
            endTime_ >= screening.getWhenScreened().getTime());
    }

    bool isDiscountableSequence(const Screening& screening) const {
        return (type_ == DiscountConditionType::SEQUENCE &&
            sequence_ == screening.getSequence());
    }   


private: 
    DiscountCondition(DiscountConditionType type, int sequence, DayOfWeek dayOfWeek, Time startTime, Time endTime) : 
        type_(type), sequence_(sequence), dayOfWeek_(dayOfWeek), startTime_(startTime), endTime_(endTime) {
    }

    DiscountConditionType type_;

    int sequence_; //type_ == SEQUENCE

    DayOfWeek dayOfWeek_;  //type_ == PERIOD
    Time startTime_;       //type_ == PERIOD 
    Time endTime_;         //type_ == PERIOD
};

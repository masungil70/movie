#pragma once

#include "screening.h"

//enum class DiscountConditionType {
//    SEQUENCE,       // 순번 조건
//    PERIOD          // 기간 조건
//};

class DiscountCondition {
public:
    virtual bool isSatisfiedBy(const Screening& screening) const = 0;
};


class SequenceDiscountCondition : public DiscountCondition {
private:
    int sequence_; //type_ == SEQUENCE
public:
    SequenceDiscountCondition(int sequence) : sequence_(sequence) {
    }

    virtual bool isSatisfiedBy(const Screening& screening) const override {
        return (sequence_ == screening.getSequence());
    }
};

class PeriodDiscountCondition : public DiscountCondition {
private:
    DayOfWeek dayOfWeek_;  //type_ == PERIOD
    Time startTime_;       //type_ == PERIOD 
    Time endTime_;         //type_ == PERIOD

public:
    PeriodDiscountCondition(DayOfWeek dayOfWeek, Time startTime, Time endTime) : 
        dayOfWeek_(dayOfWeek), startTime_(startTime), endTime_(endTime) {
    }

    virtual bool isSatisfiedBy(const Screening& screening) const override {
        return (dayOfWeek_ == screening.getWhenScreened().getDayOfWeek() &&
            startTime_ <= screening.getWhenScreened().getTime() &&
            endTime_ >= screening.getWhenScreened().getTime());
    }
};



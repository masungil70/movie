#pragma once
#include <string>
#include <vector>
#include "common.h"
#include "money.h"
#include "discountCondition.h"

using namespace std;

//enum class DiscountType {
//    AMOUNT_DISCOUNT,    // 금액 할인 정책   0
//    PERCENT_DISCOUNT,   // 비율 할인 정책   1
//    NONE_DISCOUNT       // 미적용          2
//};

class Movie {
private:
    string title_;   //영화제목
    int runningTime_; //상영시간 
    Money fee_;// 영화 관람 비용 

public:
    Movie(string title,
        int runningTime,
        Money fee) :
        title_(title),
        runningTime_(runningTime),
        fee_(fee) {
    }

    Money getFee() const {
        return fee_;
    }

    virtual Money calculateMovieFee(const Screening& screening) const = 0;

};

class DefaultDiscountMovie : public Movie {
private:
    vector<DiscountCondition*> discountConditions_;

public:
    DefaultDiscountMovie(string title,
        int runningTime,
        Money fee,
        initializer_list<DiscountCondition*>& discountConditions) :
        Movie(title, runningTime, fee) {
        discountConditions_.reserve(10);
        discountConditions_.assign(discountConditions.begin(), discountConditions.end());
    }

    bool isDiscountable(const Screening& screening) const {
        for (const auto& condition : discountConditions_) {
            if (condition->isSatisfiedBy(screening)) {
                return true;
            }
        }

        return false;
    }

    virtual Money calculateMovieFee(const Screening& screening) const override {
        return getFee().minus(calculationDiscountAmount(screening));
    }

private:
    Money calculationDiscountAmount(const Screening& screening) const {
        if (isDiscountable(screening)) {
            return calculationDiscountAmountFee(screening);
        }
        return Money::ZERO;
    }

    virtual Money calculationDiscountAmountFee(const Screening& screening) const = 0;

};

class NoneDiscountMovie : public Movie {
public:
    NoneDiscountMovie(string title, int runningTime, Money fee) :
        Movie(title, runningTime, fee) {
    }

    virtual Money calculateMovieFee(const Screening& screening) const override {
        return Money::ZERO;
    }

private:
    Money calculationDiscountAmountFee(const Screening& screening) const {
        return Money::ZERO;
    }
};

class AmountDiscountMovie : public DefaultDiscountMovie {
private:
    Money discountAmount_;
public:
    AmountDiscountMovie(string title, int runningTime, Money fee, Money discountAmount, initializer_list<DiscountCondition*>& discountConditions) :
        DefaultDiscountMovie(title, runningTime, fee, discountConditions), discountAmount_(discountAmount) {
    }
private:
    virtual Money calculationDiscountAmountFee(const Screening& screening) const override {
        return discountAmount_;
    }
};

class PercentDiscountMovie : public DefaultDiscountMovie {
private:
    double discountPercent_;
public:
    PercentDiscountMovie(string title, int runningTime, Money fee, double discountPercent, initializer_list<DiscountCondition*>& discountConditions) :
        DefaultDiscountMovie(title, runningTime, fee, discountConditions), discountPercent_(discountPercent) {
    }

private:
    virtual Money calculationDiscountAmountFee(const Screening& screening) const override{
        return getFee().times(discountPercent_);
    }
};


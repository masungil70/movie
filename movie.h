#pragma once
#include <string>
#include <vector>
#include "common.h"
#include "money.h"
#include "discountCondition.h"

using namespace std;

enum class DiscountType {
    AMOUNT_DISCOUNT,    // 금액 할인 정책   0
    PERCENT_DISCOUNT,   // 비율 할인 정책   1
    NONE_DISCOUNT       // 미적용          2
};

class Movie {
public:
    Movie(string title, int runningTime, Money fee, double discountPercent, initializer_list<DiscountCondition*>& discountConditions) :
        Movie(DiscountType::PERCENT_DISCOUNT, title, runningTime, fee, Money::ZERO, discountPercent, discountConditions) {
    }

    Movie(string title, int runningTime, Money fee, Money discountAmount, initializer_list<DiscountCondition*>& discountConditions) :
        Movie(DiscountType::AMOUNT_DISCOUNT, title, runningTime, fee, discountAmount, 0, discountConditions) {
    }

    Movie(string title, int runningTime, Money fee) :
        Movie(DiscountType::NONE_DISCOUNT, title, runningTime, fee, Money::ZERO, 0) {
    }

    //DiscountType getMovieType() const {
    //    return movieType_;
    //}

    //void setMovieType(DiscountType movieType) {
    //    movieType_ = movieType;
    //}

    Money getFee() const {
        return fee_;
    }

    //void setFee(Money fee) {
    //    fee_ = fee;
    //}

    //const vector<DiscountCondition>& getDiscountConditions() const {
    //    return discountConditions_;
    //}

    //void setDiscountConditions(vector<DiscountCondition> discountConditions) {
    //    discountConditions_ = discountConditions;
    //}

    //Money getDiscountAmount() const {
    //    return discountAmount_;
    //}

    //void setDiscountAmount(Money discountAmount) {
    //    discountAmount_ = discountAmount;
    //}

    //double getDiscountPercent() const {
    //    return discountPercent_;
    //}

    //void setDiscountPercent(double discountPercent) {
    //    discountPercent_ = discountPercent;
    //}

    bool isDiscountable(const Screening& screening) const {
        for (const auto& condition : discountConditions_) {
            if (condition->isDiscountable(screening)) {
                return true;
            }
        }

        return false;
    }

    Money calculationDiscountAmount(const Screening& screening) const {
        if (isDiscountable(screening)) {
            switch (movieType_) {
            case  DiscountType::AMOUNT_DISCOUNT:
                return discountAmount_;
            case DiscountType::PERCENT_DISCOUNT:
                return fee_.times(discountPercent_);
            case DiscountType::NONE_DISCOUNT:
                return Money::ZERO;
            }
        }
        return Money::ZERO;
    }

    Money calculationAmount(const Screening& screening) const {
        return fee_.minus(calculationDiscountAmount(screening));
    }

private:
    Movie(DiscountType movieType, 
        string title, 
        int runningTime, 
        Money fee, 
        Money discountAmount, 
        double discountPercent) :
        movieType_(movieType),
        title_(title),
        runningTime_(runningTime),
        fee_(fee),
        discountAmount_(discountAmount),
        discountPercent_(discountPercent) {
    }

    Movie(DiscountType movieType, 
        string title, 
        int runningTime, 
        Money fee, 
        Money discountAmount, 
        double discountPercent,
        initializer_list<DiscountCondition*>& discountConditions) :
        Movie(movieType, title, runningTime, fee, discountAmount, discountPercent) {
        discountConditions_.reserve(10);
        discountConditions_.assign(discountConditions.begin(), discountConditions.end());
    }

private:
	string title_;   //영화제목
	int runningTime_; //상영시간 
	Money fee_;// 영화 관람 비용 
    vector<DiscountCondition*> discountConditions_;

    DiscountType movieType_;
    Money discountAmount_; //movieType_ == AMOUNT_DISCOUNT
    double discountPercent_; //movieType_ == PERCENT_DISCOUNT
};


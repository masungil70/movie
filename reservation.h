#pragma once

#include "common.h"
#include "customer.h"
#include "screening.h"
#include "money.h"

class Reservation {
public:
    Reservation(const Customer& customer, const Screening& screening, Money fee, int audienceCount) :
        customer_(customer), screening_(screening), fee_(fee), audienceCount_(audienceCount) {
    }

    const Customer& getCustomer() const {
        return customer_;
    }

    const Screening& getScreening() const {
        return screening_;
    }

    const Money getFee() const {
        return fee_;
    }

    int getAudienceCount() const {
        return audienceCount_;
    }

    void detailOutput(ostream& out) const;

private:
    const Customer& customer_;
    const Screening& screening_;
    Money fee_;
    int audienceCount_;
}; 

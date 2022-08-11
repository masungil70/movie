#pragma once

#include "common.h"
#include "movie.h"
#include "reservation.h"
#include "screening.h"
#include "customer.h"


class ReservationAgency {
public:
    static Reservation reserve(Screening screening, Customer customer, int audienceCount);
};

//namespace ReservationAgency {
//    Reservation reserve(Screening screening, Customer customer, int audienceCount);
//};

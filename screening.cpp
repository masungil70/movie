#include "movie.h"
#include "screening.h"

Money Screening::getMovieFee() const {
    return movie_.getFee();
}

Money Screening::calculateMovieFee(int audienceCount) const {
    return movie_.calculateMovieFee(*this).times(audienceCount);
}

Reservation Screening::reserve(Customer customer, int audienceCount)
{
    return Reservation(customer, *this, calculateMovieFee(audienceCount), audienceCount);
}



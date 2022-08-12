#include "movie.h"
#include "screening.h"

Money Screening::getMovieFee() const {
    return movie_.getFee();
}

Money Screening::calculationAmount(int audienceCount) const {
    return movie_.calculationAmount(*this).times(audienceCount);
}

Reservation Screening::reserve(Customer customer, int audienceCount)
{
    return Reservation(customer, *this, calculationAmount(audienceCount), audienceCount);
}



#include <iostream>
#include "reservationAgency.h"

using namespace std;


Reservation ReservationAgency::reserve(Screening screening, Customer customer, int audienceCount) 
{
    const Movie& movie = screening.getMovie();
    bool discountable = movie.isDiscountable(screening);

    if (discountable) {
        Money discountAmount = Money::ZERO;
        switch (movie.getMovieType()) {
        case  DiscountType::AMOUNT_DISCOUNT:
            discountAmount = movie.getDiscountAmount();
            break;
        case DiscountType::PERCENT_DISCOUNT:
            discountAmount = movie.getFee().times(movie.getDiscountPercent());
            break;
        case DiscountType::NONE_DISCOUNT:
            discountAmount = Money::ZERO;
            break;
        }
        Money fee = movie.getFee().minus(discountAmount).times(audienceCount);
        return Reservation(customer, screening, fee, audienceCount);
    }
    Money fee = movie.getFee().times(audienceCount);
    return Reservation(customer, screening, fee, audienceCount);
}

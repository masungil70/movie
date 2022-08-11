#include "movie.h"
#include "screening.h"

Money Screening::getMovieFee() const {
    return movie_.getFee();
}


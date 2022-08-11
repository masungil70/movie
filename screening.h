#pragma once

#include "datetime/datetime.h"
#include "reservation.h"

using namespace datetime;

// 참조 : 1. (cpp : 참조)
//        2. (cpp : pointer)
// 값 복사 

class Screening {
public:
    Screening(Movie& movie, int sequence, DateTime whenScreened) :
        movie_(movie), sequence_(sequence), whenScreened_(whenScreened) {
    }

    int getSequence() const {
        return sequence_;
    }

    const DateTime& getWhenScreened() const {
        return whenScreened_;
    }

    bool isSequence(int sequence) const {
        return sequence_ == sequence;
    }

    const Movie& getMovie() const {
        return movie_;
    }

    //const Movie*getMovie() const {
    //    return pMovie_;
    //}
    // 
    //void setMovie(Movie* pMovie) {
    //    pMovie_ = pMovie;
    //}

    Money getMovieFee() const;

private:
    Movie& movie_;   // 영화객체
    //Movie* pMovie_;   // 영화객체

    int   sequence_; // 회차
    DateTime  whenScreened_; // 상영 시간 

};

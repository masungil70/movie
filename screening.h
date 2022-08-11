#pragma once

#include "datetime/datetime.h"
#include "reservation.h"

using namespace datetime;

// ���� : 1. (cpp : ����)
//        2. (cpp : pointer)
// �� ���� 

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
    Movie& movie_;   // ��ȭ��ü
    //Movie* pMovie_;   // ��ȭ��ü

    int   sequence_; // ȸ��
    DateTime  whenScreened_; // �� �ð� 

};

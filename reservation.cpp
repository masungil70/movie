#include <iostream>
#include "reservation.h"

using namespace std;

void Reservation::detailOutput(ostream& out) const {
    out << "\n=====================================" << endl;
    out << "회차 : " << screening_.getSequence() << endl;
    out << "상영일 : " << screening_.getWhenScreened().getDate().getString().c_str() << endl;
    out << "시작 시간 : " << screening_.getWhenScreened().getTime().getString().c_str() << endl;
    out << "1회 요금 : " << screening_.getMovieFee().getAmount() << endl;
    out << "전체요금 : " << screening_.getMovieFee().getAmount() * audienceCount_ << endl;
    out << "할인요금 : " << fee_.getAmount() << endl;
    out << "예약 인원 : " << audienceCount_ << endl;
}
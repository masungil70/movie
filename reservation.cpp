#include <iostream>
#include "reservation.h"

using namespace std;

void Reservation::detailOutput(ostream& out) const {
    out << "\n=====================================" << endl;
    out << "ȸ�� : " << screening_.getSequence() << endl;
    out << "���� : " << screening_.getWhenScreened().getDate().getString().c_str() << endl;
    out << "���� �ð� : " << screening_.getWhenScreened().getTime().getString().c_str() << endl;
    out << "1ȸ ��� : " << screening_.getMovieFee().getAmount() << endl;
    out << "��ü��� : " << screening_.getMovieFee().getAmount() * audienceCount_ << endl;
    out << "���ο�� : " << fee_.getAmount() << endl;
    out << "���� �ο� : " << audienceCount_ << endl;
}
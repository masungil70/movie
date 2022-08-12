#include <iostream>
#include "movie.h"
#include "money.h"
#include "datetime/date.h"

using namespace std;
using namespace datetime;

#if 1
	int main(int argc, char** argv) {
		//�� ������ ���� ���� ���� ��ü ���� 
		DiscountCondition sequenceCondition1{ 1 };
		DiscountCondition sequenceCondition2{ 2 };
		DiscountCondition sequenceCondition10{ 10 };

		//�Ⱓ�� ���� ���� ���� ��ü ���� 
		DiscountCondition periodCondition1{ DayOfWeek::MONDAY, {10, 0}, {11, 59} };
		DiscountCondition periodCondition2{ DayOfWeek::THURSDAY, {10, 0}, {20, 59} };
		DiscountCondition periodCondition3{ DayOfWeek::TUESDAY, {14, 0}, {14, 59} };
		DiscountCondition periodCondition4{ DayOfWeek::THURSDAY, {10, 0}, {13, 59} };

		//���� ��ü �迭 ���� 
		initializer_list<DiscountCondition> amountDiscountConditions = { sequenceCondition1, sequenceCondition10, periodCondition1, periodCondition2 };
		initializer_list<DiscountCondition> percentDiscountConditions = { periodCondition3, sequenceCondition2, periodCondition4};

		try {
			Movie avatar{ "�ƹ�Ÿ", 120, Money{10000}, Money{800}, amountDiscountConditions };

			//10% ���� ���� ��å 
			Movie titanic{"Ÿ��Ÿ��", 180, Money{11000}, 0.1, percentDiscountConditions };

			//���� ��å ����
			Movie starWars{"��Ÿ����", 210, Money{10000}};

			//�ƹ�Ÿ �� �Ͻ� ��ü ����  
			vector<Screening> avatarScreeningList = {
				Screening(avatar,  1, {2022, 1, 1, 10}),
				Screening(avatar,  2, {2022, 1, 1, 12}),
				Screening(avatar,  3, {2022, 1, 1, 14}),
				Screening(avatar,  4, {2022, 1, 1, 16}),
				Screening(avatar,  5, {2022, 1, 1, 18}),
				Screening(avatar,  6, {2022, 1, 2, 10}),
				Screening(avatar,  7, {2022, 1, 2, 12}),
				Screening(avatar,  8, {2022, 1, 2, 14}),
				Screening(avatar,  9, {2022, 1, 2, 16}),
				Screening(avatar, 10, {2022, 1, 2, 18}),
			};

			//Ÿ��Ÿ�� �� �Ͻ� ��ü ����  
			vector<Screening> titanicScreeningList = {
				Screening(titanic,  1, {2022, 1, 1, 10}),
				Screening(titanic,  2, {2022, 1, 1, 13}),
				Screening(titanic,  3, {2022, 1, 1, 15}),
				Screening(titanic,  4, {2022, 1, 1, 18}),
				Screening(titanic,  5, {2022, 1, 1, 21}),
				Screening(titanic,  6, {2022, 1, 2, 10}),
				Screening(titanic,  7, {2022, 1, 2, 13}),
				Screening(titanic,  8, {2022, 1, 2, 15}),
				Screening(titanic,  9, {2022, 1, 2, 18}),
				Screening(titanic, 10, {2022, 1, 2, 21}),
			};

			//��Ÿ���� �� �Ͻ� ��ü ����  
			vector<Screening> starWarsScreeningList = {
				Screening(starWars,  1, {2022, 1, 1, 10}),
				Screening(starWars,  2, {2022, 1, 1, 13}),
				Screening(starWars,  3, {2022, 1, 1, 15}),
				Screening(starWars,  4, {2022, 1, 1, 18}),
				Screening(starWars,  5, {2022, 1, 1, 21}),
				Screening(starWars,  6, {2022, 1, 2, 10}),
				Screening(starWars,  7, {2022, 1, 2, 13}),
				Screening(starWars,  8, {2022, 1, 2, 15}),
				Screening(starWars,  9, {2022, 1, 2, 18}),
				Screening(starWars, 10, {2022, 1, 2, 21}),
			};

			//ȫ�浿 ��ü ������ 
			Customer hong("ȫ�浿", "1");

			//ReservationAgency Ŭ������ ���� ���� �޼��带 ȣ���Ͽ� �����Ѵ�
			Reservation reserveHong = avatarScreeningList[0].reserve(hong, 2);
			reserveHong.detailOutput(cout);

			//�̼��� ��ü ������ 
			Customer lee("�̼���", "2");

			//ReservationAgency Ŭ������ ���� ���� �޼��带 ȣ���Ͽ� �����Ѵ�
			Reservation reserveLee= avatarScreeningList[1].reserve(lee, 2);
			reserveLee.detailOutput(cout);

		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}

		return 0;
	}

#endif 

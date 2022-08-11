#include "gtest/gtest.h"
#include "../datetime/date.h"

using namespace datetime;

TEST(TestDate, dateInvalidArgumentTest) {

	EXPECT_THROW({
		Date date1(-1, 1, 4);
		}, invalid_argument);

	EXPECT_THROW({
		Date date1(2020, 0, 1);
		}, invalid_argument);

	EXPECT_THROW({
		Date date1(2020, 1, 0);
		}, invalid_argument);

	EXPECT_THROW({
		Date date1(2020, 1, -4);
		}, invalid_argument);	
	
	EXPECT_THROW({
		Date date1(2020, 13, -4);
		}, invalid_argument);

	EXPECT_THROW({
		Date date1(2020, 13, 33);
		}, invalid_argument);

	EXPECT_THROW({
		Date date1(2020, 1, 32);
		}, invalid_argument);
}

TEST(TestDate, normalDateTest) {

	Date date(2022, 1, 4);
	EXPECT_EQ(2022, date.getYear());
	EXPECT_EQ(1, date.getMonth());
	EXPECT_EQ(4, date.getDay());
	EXPECT_EQ(DayOfWeek::TUESDAY, date.getDayOfWeek());
}

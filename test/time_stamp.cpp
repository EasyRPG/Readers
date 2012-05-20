#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "lsd_reader.h"


static void ToMicrosoftAccessTime() {
#define CheckTime(val, year, month, day, hour, minute, second) { \
			std::time_t const current = LSD_Reader::ToUnixTime(val);			 \
		struct tm const* const t = std::gmtime(&current); \
		 \
		assert(t->tm_year == year - 1900); \
		assert(t->tm_mon + 1 == month); \
		assert(t->tm_mday == day); \
		assert(t->tm_hour == hour); \
		assert(t->tm_min == minute); \
		assert(t->tm_sec == second); \
	} \

	// 27468.96875   27468     1975 年 3 月 15 日    .96875    11:15:00 P.M.
	CheckTime(27468.96875, 1975, 3, 15, 23, 15, 0);
	// 36836.125     36836     2000 年 11 月 6 日    .125       3:00:00 A.M.
	CheckTime(36836.125, 2000, 11, 6, 3, 0, 0);
	// 36295.0                 1999/5/15           1999/05/15 12:00:00 AM
	CheckTime(36295.0, 1999, 5, 15, 0, 0, 0);
	// 36232.9375              1999/03/13 22:30:00 1999/03/13 10:30:00 PM
	CheckTime(36232.9375, 1999, 3, 13, 22, 30, 0);

#undef CheckTime
}

static void ToUnixTime() {
	std::time_t const current = std::floor(std::time(NULL) / 1000.0) * 1000.0;
	assert(current == LSD_Reader::ToUnixTime(LSD_Reader::ToMicrosoftAccessTime(current)));
}

state void GenerateTimeStamp() {
	double const current = LSD_Reader::ToMicrosoftAccessTime(std::floor(std::time(NULL) / 1000.0) * 1000.0);
	assert(current == LSD_Reader::ToMicrosoftAccessTime(LSD_Reader::ToUnixTime(current)));
}

int main() {
  ToMicrosoftAccessTime();
  ToUnixTime();
  GenerateTimeStamp();

  return EXIT_SUCCESS;
}

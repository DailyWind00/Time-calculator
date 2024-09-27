#pragma once

# include <iostream>
# include <iomanip>

using namespace std;

class Time {
	private:
		unsigned long long time; // Time in seconds
	
	public:
		// Coplien form
		Time(
			time_t year = 0,
			time_t month = 0,
			time_t day = 0,
			time_t hour = 0,
			time_t minute = 0,
			time_t second = 0
		);
		Time(const Time& other);
		Time& operator=(const Time& other);
		~Time();

		// Getters
		time_t getTime() const;
		time_t getYear() const;
		time_t getMonth() const;
		time_t getDay() const;
		time_t getHour() const;
		time_t getMinute() const;
		time_t getSecond() const;

		// Convertions
		static time_t toYears(time_t time);
		static time_t toMonths(time_t time);
		static time_t toDays(time_t time);
		static time_t toHours(time_t time);
		static time_t toMinutes(time_t time);
		static time_t toSeconds(time_t time);

		// Operators
		friend ostream& operator<<(ostream& os, const Time& time);
		Time operator+(const Time& time) const;
		Time operator-(const Time& time) const;
		bool operator==(const Time& time) const;
		bool operator!=(const Time& time) const;
		bool operator<(const Time& time) const;
		bool operator>(const Time& time) const;
		bool operator<=(const Time& time) const;
		bool operator>=(const Time& time) const;
};
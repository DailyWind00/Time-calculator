#include "Time.hpp"

// Coplien form
Time::Time(
	time_t year,
	time_t month,
	time_t day,
	time_t hour,
	time_t minute,
	time_t second
) {
	this->time = year * 31536000 + month * 2592000 + day * 86400 + hour * 3600 + minute * 60 + second;
}

Time::Time(const Time& other) {
	this->time = other.getTime();
}

Time& Time::operator=(const Time& other) {
	this->time = other.getTime();
	return *this;
}

Time::~Time() {}

// Getters
time_t Time::getTime() const {
	return this->time;
}

time_t Time::getYear() const {
	return toYears(this->time);
}

time_t Time::getMonth() const {
	return toMonths(this->time);
}

time_t Time::getDay() const {
	return toDays(this->time);
}

time_t Time::getHour() const {
	return toHours(this->time);
}

time_t Time::getMinute() const {
	return toMinutes(this->time);
}

time_t Time::getSecond() const {
	return toSeconds(this->time);
}

// Convertions
time_t Time::toYears(time_t time) {
	return time / 31536000;
}

time_t Time::toMonths(time_t time) {
	return (time % 31536000) / 2592000;
}

time_t Time::toDays(time_t time) {
	return ((time % 31536000) % 2592000) / 86400;
}

time_t Time::toHours(time_t time) {
	return (((time % 31536000) % 2592000) % 86400) / 3600;
}

time_t Time::toMinutes(time_t time) {
	return ((((time % 31536000) % 2592000) % 86400) % 3600) / 60;
}

time_t Time::toSeconds(time_t time) {
	return ((((time % 31536000) % 2592000) % 86400) % 3600) % 60;
}

// Operators
ostream& operator<<(ostream& os, const Time& time) {
	os << setfill('0') << setw(2) << time.getYear() << ":"
		<< setfill('0') << setw(2) << time.getMonth() << ":"
		<< setfill('0') << setw(2) << time.getDay() << "-"
		<< setfill('0') << setw(2) << time.getHour() << ":"
		<< setfill('0') << setw(2) << time.getMinute() << ":"
		<< setfill('0') << setw(2) << time.getSecond();
	return os;
}

Time Time::operator+(const Time& time) const {
	return Time(0, 0, 0, 0, 0, this->time + time.getTime());
}

Time Time::operator-(const Time& time) const {
	return Time(0, 0, 0, 0, 0, this->time - time.getTime());
}

bool Time::operator==(const Time& time) const {
	return static_cast<time_t>(this->time) == time.getTime();
}

bool Time::operator!=(const Time& time) const {
	return static_cast<time_t>(this->time) != time.getTime();
}

bool Time::operator<(const Time& time) const {
	return static_cast<time_t>(this->time) < time.getTime();
}

bool Time::operator>(const Time& time) const {
	return static_cast<time_t>(this->time) > time.getTime();
}

bool Time::operator<=(const Time& time) const {
	return static_cast<time_t>(this->time) <= time.getTime();
}

bool Time::operator>=(const Time& time) const {
	return static_cast<time_t>(this->time) >= time.getTime();
}
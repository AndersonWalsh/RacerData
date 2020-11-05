#include "timestamp.h"

TimeStamp::TimeStamp(){
	hours = 0;
	minutes = 0;
	seconds = 0;
	ms = 0;
}

TimeStamp::TimeStamp(int hours, int minutes, int seconds, int ms){
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	this->ms = ms;
}

void TimeStamp::setHours(int hours){
	this->hours = hours;
}

void TimeStamp::setMinutes(int minutes){
	this->minutes = minutes;
}

void TimeStamp::setSeconds(int seconds){
	this->seconds = seconds;
}

void TimeStamp::setMS(int ms){
	this->ms = ms;
}

int TimeStamp::getHours(){
	return hours;
}

int TimeStamp::getMinutes(){
	return minutes;
}

int TimeStamp::getSeconds(){
	return seconds;
}

int TimeStamp::getMS(){
	return ms;
}

double TimeStamp::timeBetween(TimeStamp other){
	return other.convertHours() - convertHours();
}

double TimeStamp::convertHours(){
	double total_hours = hours + (minutes / 60.0) + (seconds / 3600.0) + (ms / 3600000.0);
	return total_hours;
}

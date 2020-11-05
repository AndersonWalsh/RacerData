#include "sensor.h"

Sensor::Sensor(int number, double mile_marker, TimeStamp stamp){
	this->number = number;
	this->mile_marker = mile_marker;
	this->stamp = stamp;
}

Sensor::Sensor(){}

int Sensor::getSensor(){
	return number;
}

double Sensor::getMiles(){
	return mile_marker;
}

TimeStamp Sensor::getStamp(){
	return stamp;
}

void Sensor::setStamp(TimeStamp stamp){
	this->stamp = stamp;
}

void Sensor::setSensor(int number){
	this->number = number;
}

void Sensor::setMiles(double mile_marker){
	this->mile_marker = mile_marker;
}

bool Sensor::checkContinuity(Sensor cheatyface){
	int otherNum = cheatyface.getSensor();
	if(otherNum + 1 == number || otherNum - 1 == number) return true;
	else return false;
}

bool Sensor::checkSpeed(Sensor cheatyface){
	double time = stamp.timeBetween(cheatyface.stamp);
	double distance = cheatyface.mile_marker - mile_marker;
	if(distance / time <= 14) return true;
	else return false;	
}

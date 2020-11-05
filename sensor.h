#ifndef SENSOR_H
#define SENSOR_H

#include "timestamp.h"

class Sensor{

public:
	//constructor, do nothing constructor for output purposes
	Sensor(int number, double mile_marker, TimeStamp stamp);
	Sensor();

	//getters and setters
	int getSensor();
	double getMiles();
	TimeStamp getStamp();
	void setStamp(TimeStamp stamp);
	void setSensor(int number);
	void setMiles(double mile_marker);

	//integrity checking, return false if sensors not within 1 of each other, return false if speed exceeds 14mph
	bool checkSpeed(Sensor cheatyface);	
	bool checkContinuity(Sensor cheatyface);

private:
	int number;
	double mile_marker;
	TimeStamp stamp;
};

#endif

#ifndef RACER_H
#define RACER_H

#include<string>
#include<vector>
#include "sensor.h"

class Racer{

public:
	//default constructor, constructor, copy constructor
	Racer(std::string name, int number);
	Racer(const Racer& racer);
	Racer();		

	//getters and setters
	double getTime() const;
	std::string getName() const;
	int getNum() const;
	Sensor getSensorF() const;
	Sensor getSensorL() const;
	std::vector<Sensor> getVector() const;
	void addSensor(Sensor sensor);
	void setName(std::string name);
	void setNum(int number);
	void setVector(std::vector<Sensor> sensors);

	//compute total race time in hours
	void raceTime();

	//check all sensors for discrepancies in sensor continuity or speed, * appended to name if found
	void integrityCheck();

	//overloaded operator for assigning racer to racer
	Racer& operator=(Racer& r1);

private:
	std::string name;
	int number;
	double race_time;
	std::vector<Sensor> sensors;
};

//overloaded operator for comparing racers by race_time
bool operator<(Racer r1, Racer r2);

#endif

#include "racer.h"
#include "timestamp.h"

using namespace std;

Racer::Racer(string name, int number){
	this->name = name;
	this->number = number;
}

Racer::Racer(){
	number = 0;
	race_time = 0;
	name = "Default";
}

Racer::Racer(const Racer& r1){
	this->name = r1.getName();
	this->number = r1.getNum();
	this->race_time = r1.getTime();
	this->sensors = r1.getVector();
}

string Racer::getName() const{
	return name;
}

int Racer::getNum() const{
	return number;
}

Sensor Racer::getSensorF() const{
	return sensors[0]; 
}

Sensor Racer::getSensorL() const{
	return sensors[sensors.size()-1];
}

double Racer::getTime() const{
	return race_time;
}

vector<Sensor> Racer::getVector() const{
	return sensors;
}

void Racer::addSensor(Sensor sensor){
	sensors.push_back(sensor);
}

void Racer::setNum(int number){
	this->number = number;
}

void Racer::setName(string name){
	this->name = name;
}

void Racer::setVector(vector<Sensor> sensors){
	this->sensors = sensors;
}

void Racer::integrityCheck(){
	for(int i = 0; i < sensors.size() - 1; i++){
		if(!sensors[i].checkContinuity(sensors[i+1])){ 
			name.insert(0, "*");
			break;
		}
		if(!sensors[i].checkSpeed(sensors[i+1])){
			name.insert(0, "*");
			break;
		}
	}
}

void Racer::raceTime(){
	TimeStamp stamp1, stamp2;
	stamp1 = sensors[0].getStamp();
	stamp2 = sensors[sensors.size()-1].getStamp();
	race_time = stamp1.timeBetween(stamp2);
}

bool operator<(Racer r1, Racer r2){
	if (r1.getTime() < r2.getTime()) return true;
	else return false;
}

Racer& Racer::operator=(Racer& r1){
	this->name = r1.getName();
	this->number = r1.getNum();
	this->race_time = r1.getTime();
	this->sensors = r1.getVector();
	return *this;
}

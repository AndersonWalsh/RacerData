#ifndef TIMESTAMP_H
#define TIMESTAMP_H

class TimeStamp{

public:
	//default constructor, constructor
	TimeStamp();
	TimeStamp(int hours, int minutes, int seconds, int ms);

	//getters and setters
	void setHours(int hours);
	void setMinutes(int minutes);
	void setSeconds(int seconds);
	void setMS(int ms);
	int getHours();
	int getMinutes();
	int getSeconds();
	int getMS();

	//speed functions, compute time between two stamps and convert all units of time to hours
	double timeBetween(TimeStamp other);
	double convertHours();

private:
	int hours;
	int minutes;
	int seconds;
	int ms;
};

#endif

/* Anderson Walsh
 * Lab 3: main.cpp
 * Act on race data
*/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include "racer.h"
#include "sensor.h"
#include "timestamp.h"

using namespace std;

int fileHandling(ifstream&);
void readData(ifstream&, vector<Racer>&);
void sortRacers(vector<Racer>&);
void printResults(vector<Racer>&);
void formatTime(TimeStamp, TimeStamp);

int main(){
	ifstream input;
	vector<Racer> racers;
	//if input file exists, fill racer vector, sort vector, and print results
	if(fileHandling(input)){
		readData(input, racers);
		sortRacers(racers);
		printResults(racers);	
	}
}

//precondition: vector of racers exists and is occupied
void printResults(vector<Racer>& racers){
	Sensor sensorf, sensorl;
	cout << "Name" << setw(47) << right << "Number" << setw(12) << "Time"
	<< endl << setfill('-') << setw(65) << '-' << endl << setfill(' ');
	for(int i = 0; i < racers.size(); i++){
		sensorf = racers[i].getSensorF();
		sensorl = racers[i].getSensorL();
		cout << left << setw(43) << racers[i].getName() 
		<< right << setw(6) << racers[i].getNum();
		formatTime(sensorl.getStamp(), sensorf.getStamp());
	}
} //postcondition: vector of racers' data is formatted and printed

//precondition: two timestamps from the same racer, first and last, exist
void formatTime(TimeStamp last_stamp, TimeStamp first_stamp){
	//take the difference between two timestamps in decimal hours, convert to finite units
	int hours, minutes, seconds, ms;
	double dhours = first_stamp.timeBetween(last_stamp);
	
	if(dhours >= 1){
		hours = dhours;
		dhours -= hours;
	}
	else hours = 0;
	
	dhours *= 60;
	if(dhours >= 1){
		minutes = dhours;
		dhours -= minutes;
	}
	else minutes = 0;
	
	dhours *= 60;
	if(dhours >= 1){
		seconds = dhours;
		dhours -= seconds;
	}
	else seconds = 0;
	
	dhours *= 1000;
	ms = round(dhours);

	cout << right;

	for(int i = 0; i < 8; i++) cout << ' ';

	//print out 0s based on size of (unit of time) output

	if(hours > 9) cout << hours;
	else if(hours == 0) cout << "00";
	else cout << '0' << hours;

	cout << ':';
	
	if(minutes > 9) cout << minutes;
	else if(minutes == 0) cout << "00";
	else cout << '0' << minutes;
	
	cout << ':';
	
	if(seconds > 9) cout << seconds;
	else if(seconds == 0) cout << "00";
	else cout << '0' << seconds;

	cout << ':';

	if(ms > 99) cout << ms;
	else if(ms > 9) cout << '0' << ms;
	else if(ms == 0) cout << "000";
	else cout << "00" << ms;
	
	cout << endl;
} //postcondition: difference between the timestamps, total race time, computed and formatted

//precondition: ifstream& input exists
int fileHandling(ifstream& input){
	string filename;
	cout << "Provide an input file for race data: ";
	getline(cin, filename);
	//convert filename to c string for open()
	input.open(filename.c_str());
	//if file is empty or nonexistent, error. else success
	if(input.fail()){
		cout << "File " << filename << " does not exist. Self-destruct sequence initiated.\n";
		return 0;
	}
	else if(input.peek() == EOF){
		cout << "File " << filename << " is empty. Self-destruct sequence initiated.\n";
		input.close();
		return 0;
	}
	else return 1;
} //postcondition: input file is open, SUCCESS, or file is empty/non-existent, ERROR 

//precondition: input stream is open, empty racer vector exists
void readData(ifstream& input, vector<Racer>& racers){

	char* entry = new char[100]; //largest line of data
	char* token;
	int hours, minutes, seconds, ms, racer_num, sensor_num;
	double mile_marker;

	input.getline(entry, 100);
	token = strtok(entry, "\n"); //throw out first line
	delete[] entry;
	while(input.peek() != EOF){
		entry = new char[100];
		input.getline(entry, 100);
		token = strtok(entry, ":;");
		string name(token);
		token = strtok(NULL, ":;");
		racer_num = atoi(token);
		Racer racer(name, racer_num);
		token = strtok(NULL, ":;");
		while(token != NULL){
			sensor_num = atoi(token);
			token = strtok(NULL, ":;");
			mile_marker = atof(token);
			token = strtok(NULL, ":;");
			hours = atoi(token);	
			token = strtok(NULL, ":;");
			minutes = atoi(token);
			token = strtok(NULL, ":;");
			seconds = atoi(token);
			token = strtok(NULL, ":;\0");
			ms = atoi(token);
			TimeStamp stamp(hours, minutes, seconds, ms);
			Sensor sensor(sensor_num, mile_marker, stamp);
			racer.addSensor(sensor);
			token = strtok(NULL, ":;");
		}
		racers.push_back(racer);
		delete[] entry;
	}	
	input.close();
} //postcondition: input stream is closed, racer objects instantiated and added to vector

//precondition: occupied vector of racers exists
void sortRacers(vector<Racer>& racers){
	for(int i = 0; i < racers.size(); i++){
		racers[i].integrityCheck();
		racers[i].raceTime();
	}
	sort(racers.begin(), racers.end());
} //postcondition: racer names have * if cheating detected, race time for each racer computed, vector sorted by race time

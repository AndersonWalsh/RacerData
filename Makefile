Lab3: main.o racer.o sensor.o timestamp.o
	g++ main.o racer.o sensor.o timestamp.o -o Lab3
main.o: main.cpp
	g++ -c main.cpp
racer.o: racer.cpp racer.h
	g++ -c racer.cpp
sensor.o: sensor.cpp sensor.h
	g++ -c sensor.cpp
timestamp.o: timestamp.cpp timestamp.h
	g++ -c timestamp.cpp
clean:
	rm *.o

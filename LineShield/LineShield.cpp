/*Written by Jacob Smith,Daniel Kang and Matthew Millendorf for Brandeis Robotics club
 Provides readable wrapper functions for Zumo32U4LCD.h. The program is documented for
 understanding by a general audience
 April 4 2018*/
//include the libraries necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ZumoShield.h>
#include "LineShield.h"

//assigns line sensor threshold values  to default
LineShield::LineShield() {
	lineReader.init();
	this->min = 9999;
	this->max = -9999;

}

//iterates through the array of current line sensor readings an returns the minumum and maximum reading
//does not take new reading, so can be used with printAllSensors
void LineShield::findMinMax() {
	min = reflections[0];
	max = reflections[0];
	//iterate through all sensors
	for (int i = 1; i < NUM_SENSORS; i++) {
		//update the min and max if the next reflection value is a min or max
		int reflection = reflections[i];
		if (reflection > max) {
			max = reflection;
		}
		if (reflection < min) {
			min = reflection;
		}
	}
}
//returns the minimum reflection from the last reading
int LineShield::getMin() {
	findMinMax();
	return min;
}

//returns the maximum reflection from the last reading
int LineShield::getMax() {
	findMinMax();
	return max;
}

//iterates through the array of current line sensor readings and prints each one to the robot's display
void LineShield::printAllSensors() {

	lineReader.read(reflections, 1);

	//iterate through all sensors
	for (int i = 0; i < NUM_SENSORS; i++) {
		Serial.print(i);
		Serial.print(":");
		Serial.print(reflections[i]);
		Serial.print('\t');

	}
	Serial.println("");
	delay(1000);
}

//modifies an array of the reflections of the sensor
void LineShield::getReflections(unsigned int clientArray []) {
	lineReader.read(clientArray,1);
}
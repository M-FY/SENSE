/*
10/22/15
Code Written by Daniel, debugged by James
*/

#include "Arduino.h"
#include "Pressure.h"
#include <cmath>

Pressure:: Pressure (int pinNumber) {
	pinNum = pinNumber;
	pinMode(pinNum, INPUT);
	
}
double Pressure::getVoltage() {
	update();
	return currentVoltage;
}

double Pressure::getPressure() {
	update();
	return currentPressure;
}

double Pressure::getAirSpeed() {
	update();
	return currentAirSpeed;
}

double Pressure::update() {
	currentVoltage = analogRead(pinNum);
	currentPressure = currentVoltage + 2.5;
	double inchMerc = .9853 * currentPressure;
	double staticPressure = 29.92126;
	double speedSound = 661.4788;
	currentAirSpeed = speedSound * sqrt(5 * (pow(
		inchMerc / staticPressure + 1), 2/7) - 1);
}

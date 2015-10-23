#include "Arduino.h"

class Pressure {
	public:
		Pressure(int pin);
		double getVoltage();
		double getPressure();
		double getAirSpeed();
		void update();
		
	private:
		double currentVoltage;
		double currrentPressure;
		double currentAirSpeed;
		int pinNum;
		
}
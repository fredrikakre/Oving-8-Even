#include "Car.h"
bool Car::hasFreeSeats() const {
	if (freeSeats > 0) {
		return true;
	}
	return false;
}

void Car::reserveFreeSeat() {
	freeSeats -= 1;	
}

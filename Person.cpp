#include "Person.h"
void Person::setEmail(string mail){
	email = mail;
}

bool Person::hasAvailableSeats() const {
	if (ptrCar->hasFreeSeats()) {
		return true;
	} return false;
}

ostream& operator<<(ostream& os, const  Person& p) {
	os << "Name:  " << p.name << "\t Email: " << p.email << endl;
	return os;
}
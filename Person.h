#pragma once
#include "Graph.h"
#include "Simple_window.h"
#include "Car.h"
class Person {
private:
	string name;
	string email;
	Car *ptrCar;
public:
	Person(string name, string email, Car *ptrCar = nullptr) :
		name{ name }, email{ email }, ptrCar{ ptrCar } {};
	string getName() const { return name; };
	string getEmail() const { return email; };
	void setEmail(string email);
	bool hasAvailableSeats() const;
	friend ostream& operator<<(ostream& os, const Person& p);
};

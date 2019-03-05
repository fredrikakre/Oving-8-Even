#pragma once
class Car {
private:
	int freeSeats;
public:
	Car(int n) : freeSeats{ n } {};
	bool hasFreeSeats() const;
	void reserveFreeSeat();
};
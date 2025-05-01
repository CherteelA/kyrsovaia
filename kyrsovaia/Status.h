#pragma once
#include <vector>
#include "Passenger.h"

class Status {
	std::vector<Passenger*> passengers;
public:
	~Status();
	Status() = default;
	void addPassenger(Passenger* newPassenger);
	void printStatus();
};
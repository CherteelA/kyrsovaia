#pragma once
#include "Passenger.h"
#include <queue>
#include <thread>

class DepartingService {
	std::queue<DepartingPassenger*> checkInQueue;
	std::queue<DepartingPassenger*> checkPassengerQueue;
	std::queue<DepartingPassenger*> pasportControleQueue;
public:
	DepartingService() = default;
	void addPassengber(DepartingPassenger* newPassenger);
	void checkInPassenger();
	void checkPassenger();
	void PasportControlPassenger();
	int getSizeCheckInQueue();
	int getSizeCheckPassengerQueue();
	int getSizePasportControleQueue();
};


class ArrivingService {
	std::queue<ArrivingPassenger*> checkInQueue;
	std::queue<ArrivingPassenger*> pasportControleQueue;
public:
	ArrivingService() = default;
	void addPassengber(ArrivingPassenger* newPassenger);
	void checkInPassenger();
	void PasportControlPassenger();
	int getSizeCheckInQueue();
	int getSizePasportControleQueue();
};
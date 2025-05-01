#include "Service.h"


void DepartingService::addPassengber(DepartingPassenger& newPassenger) {
	checkInQueue.emplace(newPassenger);
}


void DepartingService::checkInPassenger() {
	DepartingPassenger passenger = checkInQueue.front();
	checkInQueue.pop();
	passenger.checkInPassenger();
	if (passenger.getStatus() == 1) {
		checkPassengerQueue.emplace(passenger);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void DepartingService::checkPassenger() {
	DepartingPassenger passenger = checkPassengerQueue.front();
	checkPassengerQueue.pop();
	passenger.checkPassenger();
	if (passenger.getStatus() == 2) {
		pasportControleQueue.emplace(passenger);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void DepartingService::PasportControlPassenger() {

	DepartingPassenger passenger = pasportControleQueue.front();
	pasportControleQueue.pop();
	passenger.pasportControle();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int DepartingService::getSizeCheckInQueue() {
	return checkInQueue.size();
}

int DepartingService::getSizeCheckPassengerQueue() {
	return checkPassengerQueue.size();
}

int DepartingService::getSizePasportControleQueue() {
	return pasportControleQueue.size();
}
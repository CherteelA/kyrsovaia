#include "Passenger.h"
#include "Service.h"

void ArrivingService::addPassengber(ArrivingPassenger& newPassenger) {
	checkInQueue.emplace(newPassenger);
}


void ArrivingService::checkInPassenger() {
	ArrivingPassenger passenger = checkInQueue.front();
	checkInQueue.pop();
	passenger.checkInPassenger();
	if (passenger.getStatus() == 1) {
		pasportControleQueue.emplace(passenger);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void ArrivingService::PasportControlPassenger() {
	ArrivingPassenger passenger = pasportControleQueue.front();
	pasportControleQueue.pop();
	passenger.pasportControle();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int ArrivingService::getSizeCheckInQueue() {
	return checkInQueue.size();
}

int ArrivingService::getSizePasportControleQueue() {
	return pasportControleQueue.size();
}
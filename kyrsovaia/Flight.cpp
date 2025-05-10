#include "Flight.h"




Flight::Flight(int numb, int seatsSize, bool setAbroad) : number(numb), maxSeats(seatsSize), seatIndex(1), abroad(setAbroad){
	
}

int Flight::getNumber(){
	return number;
}

int Flight::getSeatNumber() {
	if (seatIndex == maxSeats) {
		return -1;
	}
	return seatIndex++;
}

bool Flight::getAbroadStat() {
	return abroad;
}

void Flight::showData() {
	std::cout << number << " " << maxSeats << " " << abroad << std::endl;
}


/*------------------------FlightsContainer---------------------------------------------------*/
std::vector<Flight> FlightsContainer::Flights;

void FlightsContainer::addFlight(Flight& F) {
	for (Flight i : Flights) {
		if (i.getNumber() == F.getNumber()) {
			std::cout << "\nFlight number: " << F.getNumber() << " already\n";
			return;
		}
	}
	Flights.push_back(F);
}

int FlightsContainer::getSeatNumber(int flightNumber) {
	for (Flight &i : Flights) {
		if (i.getNumber() == flightNumber) {
			return i.getSeatNumber();
		}
	}
	return -2;
}


int FlightsContainer::getStatAbroad(int flightNumber) {
	for (Flight &i : Flights) {
		if (i.getNumber() == flightNumber) {
			return i.getAbroadStat() ? 1 : 0;
		}
	}
	return -1;
}

void FlightsContainer::showFlights() {
	for (Flight i : Flights) {
		i.showData();
	}
}
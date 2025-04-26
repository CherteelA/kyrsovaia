#include "Flight.h"


std::vector<Flight> FlightsContainer::Flights;

Flight::Flight(int numb, int seatsSize) : number(numb), maxSeats(seatsSize), seatIndex(1){
	
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


void FlightsContainer::addFlight(Flight& F) {
	Flights.push_back(F);
}

int FlightsContainer::getSeatNumber(int flightNumber) {
	for (Flight i : Flights) {
		if (i.getNumber() == flightNumber) {
			return i.getSeatNumber();
		}
	}
	return -2;
}
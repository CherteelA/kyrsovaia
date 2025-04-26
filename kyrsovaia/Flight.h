
#ifndef FLIGHT_H
#define FLIGHT_H
#pragma once
#include <vector>

class Flight {
	int number;
	int maxSeats;
	
	int seatIndex;
public:
	Flight(int numb, int seatsSize);
	int getNumber();
	int getSeatNumber();
};


class FlightsContainer {
	static std::vector<Flight> Flights;
public:
	FlightsContainer() = default;
	void addFlight(Flight& F);
	int getSeatNumber(int flightNumber);
};


#endif // FLIGHT_H
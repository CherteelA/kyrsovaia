
#ifndef FLIGHT_H
#define FLIGHT_H
#pragma once
#include <vector>
#include <iostream>

class Flight {
	int number;
	int maxSeats;
	int seatIndex;
	bool abroad;//true за границей
public:
	Flight(int numb, int seatsSize, bool setAbroad);
	int getNumber();
	int getSeatNumber();
	bool getAbroadStat();
	void showData();
};


class FlightsContainer {
	static std::vector<Flight> Flights;
public:
	FlightsContainer() = default;
	void addFlight(Flight& F);
	int getSeatNumber(int flightNumber);
	int getStatAbroad(int flightNumber);
	void showFlights();
};





#endif // FLIGHT_H
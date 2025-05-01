#include "Passenger.h"


Passenger* CreatArrivingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, std::string&& pasport) {
    return new ArrivingPassenger(name, surname, thirdName, baggage, carryOn, pasport);
}


Passenger* CreatDepartingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, std::string&& pasport) {
    return new DepartingPassenger(name, surname, thirdName, baggage, carryOn, pasport);
}










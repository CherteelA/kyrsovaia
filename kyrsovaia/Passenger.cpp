#include "Passenger.h"







ArrivingPassenger::ArrivingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, bool& abroad, std::string& pasport)
    : name(name),
    surname(surname),
    thirdName(thirdName),
    baggage(baggage),
    carryon(carryOn),
    abroad(abroad),
    pasportData(pasport)
{

}

std::string ArrivingPassenger::getName()  {
    return name;
}

std::string ArrivingPassenger::getSurname() {
    return surname;
}

std::string ArrivingPassenger::getThirdname() {
    return thirdName;
}

int ArrivingPassenger::getTicketNumber() {
    return numberTicket;
}

int ArrivingPassenger::getSeatNumber() {
    return numberSeat;
}

int ArrivingPassenger::getNumberFlight() {
    return numberFlight;
}

int ArrivingPassenger::getNumberTicket() {
    return numberTicket;
}

std::string ArrivingPassenger::getPasportData() {
    return pasportData;
}

int ArrivingPassenger::getStatus() {
    return status;
}




Passenger* CreatArrivingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, bool&& abroad, std::string&& pasport) {
    return new ArrivingPassenger(name, surname, thirdName, baggage, carryOn, abroad, pasport);
}


Passenger* CreatDepartingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, bool&& abroad, std::string&& pasport) {
    return new DepartingPassenger(name, surname, thirdName, baggage, carryOn, abroad, pasport);
}

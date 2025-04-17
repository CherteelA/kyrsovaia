#include "Passenger.h"


DepartingPassenger::DepartingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, bool& abroad, int numberFlight)
    : name(name),
    surname(surname),
    thirdName(thirdName),
    baggage(baggage),
    carryon(carryOn),
    abroad(abroad),
    numberFlight(numberFlight)
{
    status = 0;
}

std::string DepartingPassenger::getName() {
    return name;
}

std::string DepartingPassenger::getSurname() {
    return surname;
}

std::string DepartingPassenger::getThirdname() {
    return thirdName;
}

int DepartingPassenger::getTicketNumber() {
    return numberTicket;
}

int DepartingPassenger::getSeatNumber() {
    return numberSeat;
}

void DepartingPassenger::checkInPassenger() {

}
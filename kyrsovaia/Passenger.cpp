#include "Passenger.h"
#include "DbConnector.h"

DepartingPassenger::DepartingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, bool& abroad, std::string& pasport)
    : name(name),
    surname(surname),
    thirdName(thirdName),
    baggage(baggage),
    carryon(carryOn),
    abroad(abroad),
    pasportData(pasport)
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

int DepartingPassenger::getNumberFlight() {
    return numberFlight;
}

int DepartingPassenger::getNumberTicket() {
    return numberTicket;
}

std::string DepartingPassenger::getPasportData() {
    return pasportData;
}


int DepartingPassenger::checkInPassenger() {
    DbConnector *con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT flightnumber, numberTicket FROM passenger WHERE pasportData = " + pasportData;
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        return 1;
    }
    std::vector<std::vector<int>>;
    while (con->getRes()->next()) {
        int flightnumber = con->getRes()->getInt("flightnumber");
        int numberTicket = con->getRes()->getInt("numberTicket");

        std::cout << flightnumber << " " << numberTicket << std::endl;
    }
    
    
}




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





Passenger* CreatArrivingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, bool&& abroad, std::string&& pasport) {
    return new ArrivingPassenger(name, surname, thirdName, baggage, carryOn, abroad, pasport);
}


Passenger* CreatDepartingPassenger::createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, bool&& abroad, std::string&& pasport) {
    return new DepartingPassenger(name, surname, thirdName, baggage, carryOn, abroad, pasport);
}

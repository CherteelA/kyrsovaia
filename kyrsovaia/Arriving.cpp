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

std::string ArrivingPassenger::getName() {
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

int ArrivingPassenger::pasportControle() {
    
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT name, surname, thirdname FROM abroad WHERE pasportData = '" + pasportData + "'";
    con->request(std::move(sql));
    if (con->getRes() == nullptr) {
        status = -2;
        return 1;
    }
    if (con->getRes()->next()) {
        std::string name = con->getRes()->getString("name");
        std::string surname = con->getRes()->getString("surname");
        std::string thirdname = con->getRes()->getString("thirdname");
        if (name != this->name || surname != this->surname || thirdName != this->thirdName) {
            status = -3;
        }
    }
    else {
        std::cout << "Passenger not found";
        status = -3;
        return 1;
    }

    status = 3;
}
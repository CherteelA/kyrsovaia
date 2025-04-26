#include "Passenger.h"



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

int DepartingPassenger::getStatus() {
    return status;
}


int DepartingPassenger::checkInPassenger() {
    if (status != 0) {
        return 1;
    }
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT flightnumber, numberTicket, baggage FROM passenger WHERE pasportData = " + pasportData;
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        status = -1;
        return 1;
    }
    std::vector<std::vector<int>>;
    int baggageNow = 0;
    while (con->getRes()->next()) {
        this->numberFlight = con->getRes()->getInt("flightnumber");
        this->numberTicket = con->getRes()->getInt("numberTicket");
        baggageNow = con->getRes()->getInt("baggage");
    }


    if (baggageNow == 0 && !baggage) {
        status - 1;
        return 1;
    }

    FlightsContainer conteiner;

    int temp = conteiner.getSeatNumber(numberFlight);
    if (temp > 0) {
        this->numberSeat = temp;
    }
    else {
        status = -1;
        return 1;
    }

    status = 1;
}


int DepartingPassenger::checkPassenger() {
    if (status == 1) {
        status = 2;
    }
    else {
        return 1;
    }
}

int DepartingPassenger::pasportControle() {
    if (status != 2) {
        return 1;
    }
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT name, surname, thirdname FROM abroad WHERE pasportData = " + pasportData;
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        status = -2;
        return 1;
    } 
    while (con->getRes()->next()) {
        std::string name = con->getRes()->getString("name");
        std::string surname = con->getRes()->getString("surname");
        std::string thirdname = con->getRes()->getString("thirdname");
        if (name != this->name || surname != this->surname || thirdName != this->thirdName) {
            status = -3;
        }
    }

    status = 3;

}
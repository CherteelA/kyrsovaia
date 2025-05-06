#include "Passenger.h"

ArrivingPassenger::ArrivingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, std::string& pasport)
    : name(name),
    surname(surname),
    thirdName(thirdName),
    baggage(baggage),
    carryon(carryOn),
    pasportData(pasport),
    abroad(false)
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


int ArrivingPassenger::getNumberFlight() {
    return numberFlight;
}


std::string ArrivingPassenger::getPasportData() {
    return pasportData;
}

int ArrivingPassenger::getStatus() {
    return status;
}

bool ArrivingPassenger::getAbroadStatus() {
    return abroad;
}

int ArrivingPassenger::getType() {
    return 1;
}

int ArrivingPassenger::checkInPassenger() {
    if (status != 0) {
        return 1;
    }
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT name, surname, thirdname, flightnumber FROM arrivedpassenger WHERE pasportData = '" + pasportData + "'";
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        status = -1;
        return 1;
    }
    std::vector<std::vector<int>>;
    std::string surnameNow;
    std::string nameNow;
    std::string thirdnameNow;
    if (con->getRes()->next()) {
        nameNow = con->getRes()->getString("name");
        surnameNow = con->getRes()->getString("surname");
        thirdnameNow = con->getRes()->getString("thirdname");
        this->numberFlight = con->getRes()->getInt("flightnumber");
        if (nameNow != this->name || surnameNow != this->surname || thirdnameNow != this->thirdName) {
            std::cout << "different data\n";
            status = -1;
            return 1;
        }
    }
    else {
        std::cout << "Passenger not found\n";
        status = -1;
        return 1;
    }

    
    status = 1;
}

int ArrivingPassenger::pasportControle() {
    if (status != 1) {
        return 1;
    }

    FlightsContainer Flights;
    int stat = Flights.getStatAbroad(numberFlight);
    if (stat == 0) {
        status = 3;
        return 0;
    }
    else if (stat == -1) {
        status = -4;
        return 1;
    }

    abroad = true;
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT name, surname, thirdname FROM abroad WHERE pasportData = '" + pasportData + "'";
    con->request(std::move(sql), "airport");

    if (con->getRes() == nullptr) {
        status = -3;
        return 1;
    }
    if (con->getRes()->next()) {
        std::string name = con->getRes()->getString("name");
        std::string surname = con->getRes()->getString("surname");
        std::string thirdname = con->getRes()->getString("thirdname");
        if (name != this->name || surname != this->surname || thirdName != this->thirdName) {
            status = -3;
            return 1;
        }
    }
    else {
        std::cout << "Passenger not found\n";
        status = -3;
        return 1;
    }

    status = 3;
}
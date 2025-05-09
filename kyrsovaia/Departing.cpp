#include "Passenger.h"



DepartingPassenger::DepartingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, std::string& pasport)
    : name(name),
    surname(surname),
    thirdName(thirdName),
    baggage(baggage),
    carryon(carryOn),
    pasportData(pasport),
    abroad(false)
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

int DepartingPassenger::getNumberFlight() {
    return numberFlight;
}

std::string DepartingPassenger::getPasportData() {
    return pasportData;
}

int DepartingPassenger::getStatus() {
    return status;
}

bool DepartingPassenger::getAbroadStatus() {
    return abroad;
}

int DepartingPassenger::getType() {
    return 0;
}

int DepartingPassenger::checkInPassenger() {
    if (status != 0) {
        return 1;
    }
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT flightnumber, numberTicket, baggage, checkIn FROM passenger WHERE pasportData = '" + pasportData + "'";
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        status = -1;
        return 1;
    }
    
    int baggageStatus = 0;
    if (con->getRes()->next()) {
        this->numberFlight = con->getRes()->getInt("flightnumber");
        this->numberTicket = con->getRes()->getInt("numberTicket");
        baggageStatus = con->getRes()->getInt("baggage");
        int checkStatus = con->getRes()->getInt("checkIn");
        if (checkStatus == 1) {
            status = -1;
            return 1;
        }
        else {
            
            std::string sql = "UPDATE passenger SET checkIn = 1 WHERE pasportData = '" + pasportData + "'";
            con->request(std::move(sql), "airport");
        }
    }
    else {
        std::cout << "Passenger not found\n";
        status = -1;
        return 1;
    }


    if (baggageStatus == 0 && baggage) {
        status = -1;
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
    FlightsContainer Flights;
    int stat = Flights.getStatAbroad(numberFlight);
    if(stat == 0){
        status = 3;
        return 0;
    }
    else if(stat == -1){
        status = -4;
        return 1;
    }

    abroad = true;
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");
    std::string sql = "SELECT name, surname, thirdname FROM abroad WHERE pasportData = '" + pasportData+"'";
    con->request(std::move(sql), "airport");
    if (con->getRes() == nullptr) {
        status = -3;
        return 1;
    } 
    if (con->getRes()->next()) {
        std::string nameNew = con->getRes()->getString("name");
        std::string surnameNew = con->getRes()->getString("surname");
        std::string thirdnameNew = con->getRes()->getString("thirdname");
    
        if (nameNew != this->name || surnameNew != this->surname || thirdnameNew != this->thirdName) {
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
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





void addTestData() {
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");


    std::string sql = "TRUNCATE TABLE passenger";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexsey', 'Sitnikov', 'Pavlovich', '1214', 1234, '1419789345', 1)";
    con->request(std::move(sql));

    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Nikita', 'Plyakin', 'Fndreevich', '1214', 1223, '1419786456', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexei', 'Sokolov', 'Nikolaevna', '3456', 8819, '4131556864', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Dmitry', 'Kuznetsov', 'Sergreevna', '3456', 1717, '6636059702', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Ivan', 'Ivanov', 'Denisovna', '2345', 6656, '4913449509', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Nikita', 'Mikhailov', 'Sergreevna', '2345', 7723, '5510041997', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Maria', 'Mikhailova', 'Nikolaevna', '2345', 2279, '7600210580', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Andrey', 'Novikov', 'Vladimirovich', '2345', 7321, '9304237263', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Anastasia', 'Vasileva', 'Vladimirovich', '2345', 7472, '6749268564', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Nikita', 'Sokolov', 'Alexandrovna', '2345', 3019, '6689951261', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Alexei', 'Petrov', 'Ivanovich', '3456', 8102, '8346661111', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Maria', 'Kuznetsova', 'Viktorovna', '3456', 5703, '2535501582', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Ivan', 'Vasilev', 'Vladimirovich', '2345', 2095, '1906325333', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Pavel', 'Sokolov', 'Ivanovich', '2345', 8958, '9990465137', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Alexei', 'Sokolov', 'Alexandrovna', '2345', 2661, '7706943996', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Svetlana', 'Sokolova', 'Alexeevna', '3456', 9679, '7831891150', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Svetlana', 'Plyakina', 'Viktorovna', '1214', 6605, '7930113614', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Anastasia', 'Vasileva', 'Nikolaevna', '3456', 5473, '1287685416', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Andrey', 'Smirnov', 'Yegorovna', '3456', 3102, '8846255394', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Maria', 'Novikova', 'Viktorovna', '1214', 4510, '7477034402', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Svetlana', 'Smirnova', 'Viktorovna', '2345', 3579, '4233966017', 1)";
    con->request(std::move(sql));

    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Pavel', 'Petrov', 'Vladimirovich', '2345', 2330, '2385242969', 0)";
    con->request(std::move(sql));


    /*---------------------------------- - abroad------------------------------------------------*/


    sql = "TRUNCATE TABLE abroad";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
        \VALUES('Alexsey', 'Sitnikov', 'Pavlovich', '1419789345')";
    con->request(std::move(sql));

    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
        \VALUES('Nikita', 'Plyakin', 'Fndreevich', '1419786456')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
        \VALUES('Alexei', 'Sokolov', 'Nikolaevna', '4131556864')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Dmitry', 'Kuznetsov', 'Sergreevna', '6636059702')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Ivan', 'Ivanov', 'Denisovna', '4913449509')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Nikita', 'Mikhailov', 'Sergreevna', '5510041997')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Maria', 'Mikhailova', 'Nikolaevna', '7600210580')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Andrey', 'Novikov', 'Vladimirovich', '9304237263')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Anastasia', 'Vasileva', 'Vladimirovich', '6749268564')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Nikita', 'Sokolov', 'Alexandrovna', '6689951261')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Alexei', 'Petrov', 'Ivanovich', '8346661111')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Maria', 'Kuznetsova', 'Viktorovna', '2535501582')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Ivan', 'Vasilev', 'Vladimirovich', '1906325333')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Pavel', 'Sokolov', 'Ivanovich', '9990465137')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Alexei', 'Sokolov', 'Alexandrovna', '7706943996')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Svetlana', 'Sokolova', 'Alexeevna', '7831891150')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Svetlana', 'Plyakina', 'Viktorovna', '7930113614')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Anastasia', 'Vasileva', 'Nikolaevna', '1287685416')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Andrey', 'Smirnov', 'Yegorovna', '8846255394')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Maria', 'Novikova', 'Viktorovna', '7477034402')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Svetlana', 'Smirnova', 'Viktorovna', '4233966017')";
    con->request(std::move(sql));

    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Pavel', 'Petrov', 'Vladimirovich', '2385242969')";
    con->request(std::move(sql));
}
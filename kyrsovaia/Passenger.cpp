#include "Passenger.h"







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
        \VALUES('Nikita', 'Plyakin', 'Andreevich', '1214', 1223, '1419786456', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexei', 'Sokolov', 'Nikolaevich', '3456', 8819, '4131556864', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Dmitry', 'Kuznetsov', 'Sergreevich', '3456', 1717, '6636059702', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Ivan', 'Ivanov', 'Denisovich', '2345', 6656, '4913449509', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Nikita', 'Mikhailov', 'Sergreevich', '2345', 7723, '5510041997', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Maria', 'Mikhailova', 'Nikolaevna', '2345', 2279, '7600210580', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Andrey', 'Novikov', 'Vladimirovich', '2345', 7321, '9304237263', 0)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Anastasia', 'Vasileva', 'Vladimirovna', '2345', 7472, '6749268564', 1)";
    con->request(std::move(sql));


    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
    \VALUES('Nikita', 'Sokolov', 'Alexandrovich', '2345', 3019, '6689951261', 1)";
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
    \VALUES('Alexei', 'Sokolov', 'Alexandrovich', '2345', 2661, '7706943996', 1)";
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
    \VALUES('Andrey', 'Smirnov', 'Yegorovich', '3456', 3102, '8846255394', 0)";
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
        \VALUES('Nikita', 'Plyakin', 'Andreevich', '1419786456')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
        \VALUES('Alexei', 'Sokolov', 'Nikolaevich', '4131556864')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Dmitry', 'Kuznetsov', 'Sergreevich', '6636059702')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Ivan', 'Ivanov', 'Denisovich', '4913449509')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Nikita', 'Mikhailov', 'Sergreevich', '5510041997')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Maria', 'Mikhailova', 'Nikolaevna', '7600210580')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Andrey', 'Novikov', 'Vladimirovich', '9304237263')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Anastasia', 'Vasileva', 'Vladimirovna', '6749268564')";
    con->request(std::move(sql));


    sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) \
    \VALUES('Nikita', 'Sokolov', 'Alexandrovich', '6689951261')";
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
    \VALUES('Alexei', 'Sokolov', 'Alexandrovich', '7706943996')";
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
    \VALUES('Andrey', 'Smirnov', 'Yegorovich', '8846255394')";
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

    /*---------------------------------ArrivedPassengers-----------------------------------------------*/

    sql = "TRUNCATE TABLE arrivedpassenger";

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Svetlana', 'Smirnova', 'Ivanovna', '1914', '8001926630')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Maria', 'Kuznetsova', 'Fedorovna', '1914', '2880524289')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Svetlana', 'Mikhailova', 'Fedorovna', '3314', '8063450966')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Ekaterina', 'Smirnova', 'Alexeevna', '3314', '9819898220')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Svetlana', 'Mikhailova', 'Ivanovna', '1232', '3331737623')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Andrey', 'Ivanov', 'Vladimirovich', '1232', '3870666995')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Andrey', 'Kuznetsov', 'Alexandrovich', '3314', '2193479421')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Ekaterina', 'Vasileva', 'Fedorovna', '1232', '3895906955')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Maria', 'Kuznetsova', 'Nikolaevna', '1914', '1363448532')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Nikita', 'Plyakin', 'Nikolaevich', '1914', '3001623348')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Ekaterina', 'Smirnova', 'Nikolaevna', '3314', '5618066238')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Svetlana', 'Sokolova', 'Fedorovna', '1232', '6574741981')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Alexei', 'Sokolov', 'Yegorovich', '1914', '5615668761')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Nikita', 'Plyakin', 'Alexandrovich', '1232', '7526298498')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Anastasia', 'Sokolova', 'Sergreevna', '1232', '5581204287')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Svetlana', 'Vasileva', 'Fedorovna', '1914', '2515073117')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Dmitry', 'Kuznetsov', 'Nikolaevich', '1914', '1246263780')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Ekaterina', 'Smirnova', 'Nikolaevna', '3314', '2715209858')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Nikita', 'Petrov', 'Vladimirovich', '3314', '6108445724')";
    con->request(std::move(sql));

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Maria', 'Smirnova', 'Alexandrovna', '3314', '4460826678')";
    con->request(std::move(sql));
}






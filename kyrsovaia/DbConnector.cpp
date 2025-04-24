//
// Created by admin on 13.04.2025.
//

#include "DbConnector.h"

DbConnector* DbConnector::current = nullptr;
int DbConnector::count = 0;


DbConnector* DbConnector::getInstance(std::string &&host, std::string &&nameUsser, std::string &&paswword) {
    if (current == nullptr) {

        current = new DbConnector(std::move(host), std::move(nameUsser), std::move(paswword));
    }
    count++;
    return current;
}

DbConnector::~DbConnector() {
    if (current != nullptr && --count == 0) {
        delete current;
        current = nullptr;
        isConnect = false;
    }
}

DbConnector::DbConnector(std::string &&host, std::string &&nameUsser, std::string &&paswword) {
    driver = nullptr;
    con = nullptr;
    stmt = nullptr;
    res = nullptr;
    isConnect = false;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, nameUsser, paswword);
        isConnect = true;
    }
    catch (std::exception& e) {
        e.what();
        std::cout << "\nTry connection to database again\n";
        isConnect = false;
        driver = nullptr;
        con = nullptr;
        stmt = nullptr;
        res = nullptr;
    }

    
}

void DbConnector::request(std::string &&sql, std::string &&nameDb) {
    if (isConnect) {
        try {
            con->setSchema(nameDb);
            stmt = con->createStatement();
            res = stmt->executeQuery(sql);
            //res = stmt->executeQuery("SELECT flightnumber, numberTicket FROM passenger WHERE name = 'Alexsey' AND 'surname' = 'Sitnikov' AND thirdname = 'Pavlovich'");
        }
        catch (std::exception &e) {
            e.what();
            std::cout << "\nTry request again\n";
        }
    }
}

sql::ResultSet* DbConnector::getRes() {
    return res;
}

bool DbConnector::getIsConnect() {
    return isConnect;
}


//try {
//    sql::mysql::MySQL_Driver* driver = nullptr;
//    sql::Connection* con = nullptr;
//
//
//    driver = sql::mysql::get_mysql_driver_instance();
//    con = driver->connect("tcp://127.0.0.1:3306", "root", "777809");
//    con->setSchema("airport");
//
//    // Создаем statement для выполнения запросов
//    sql::Statement* stmt = con->createStatement();
//
//    // Выполняем SELECT-запрос
//    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM passenger");
//    while (res->next()) {
//        // Извлекаем данные по именам столбцов
//        int id = res->getInt("id");
//        std::string name = res->getString("name");
//        std::string surname = res->getString("surname");
//        std::string thirdname = res->getString("thirdname");
//        int flightNumber = res->getInt("flightnumber");
//
//        // Выводим данные на экран
//        std::cout << "ID: " << id
//            << ", Name: " << name
//            << ", Surname: " << surname
//            << ", Third Name: " << thirdname
//            << ", Flight Number: " << flightNumber << std::endl;
//    }
//
//    delete res;
//}
//catch (std::exception& e) {
//    e.what();
//}
//
// Created by admin on 13.04.2025.
//

#include "DbConnector.h"

DbConnector* DbConnector::getInstance() {
    if (current == nullptr) {

        current = new DbConnector;
    }
    count++;
    return current;
}

DbConnector::~DbConnector() {
    if (current != nullptr && --count == 0) {
        delete current;
        current = nullptr;
    }
}

DbConnector::DbConnector() {
    sql::mysql::MySQL_Driver* driver = nullptr;
    sql::Connection* con = nullptr;
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;
}

void DbConnector::creatConn(std::string host, std::string nameUsser, std::string paswword, std::string nameDb) {

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, nameUsser, paswword);
        con->setSchema(nameDb);
        stmt = con->createStatement();

    }
    catch (std::exception &e) {
        e.what();
        std::cout << "\nTry connection to database again\n";
    }
}

void DbConnector::request(std::string sql) {
    if (stmt != nullptr) {
        try {
            res = stmt->executeQuery(sql);
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
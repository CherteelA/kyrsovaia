//
// Created by admin on 13.04.2025.
//

#include "DbConnector.h"

DbConnector* DbConnector::current = nullptr;
int DbConnector::count = 0;


DbConnector* DbConnector::getInstance(std::string&& host, std::string&& nameUsser, std::string&& paswword) {
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
    if (driver != nullptr) {
        delete driver;
        driver = nullptr;
    }
    if (con != nullptr) {
        delete con;
        con = nullptr;
    }
    if (res != nullptr) {
        delete res;
        res = nullptr;
    }
    if (stmt != nullptr) {
        delete stmt;
        stmt = nullptr;
    }
}

DbConnector::DbConnector(std::string&& host, std::string&& nameUsser, std::string&& paswword) {
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
        std::cerr << e.what();
        std::cout << "\nTry connection to database again\n";
        isConnect = false;
        driver = nullptr;
        con = nullptr;
        stmt = nullptr;
        res = nullptr;
    }


}

void DbConnector::request(std::string&& sql, std::string &&dbName) {
    if (isConnect) {
        try {
            if (res != nullptr) {
                delete res;
                res = nullptr;
            }
            if (stmt != nullptr) {
                delete stmt;
                stmt = nullptr;
            }
            con->setSchema(dbName);
            stmt = con->createStatement();
            if (sql[0] == 'S') {
                res = stmt->executeQuery(sql);
            }
            else {
                stmt->executeUpdate(sql);
            }
        }
        catch (std::exception& e) {
            std::cerr << "Error executing query: " << sql << "\n";
            std::cerr << "Error message: " << e.what() << "\n";
            std::cerr << "Try request again\n";
        }
    }
}

sql::ResultSet* DbConnector::getRes() {
    return res;
}

bool DbConnector::getIsConnect() {
    return isConnect;
}



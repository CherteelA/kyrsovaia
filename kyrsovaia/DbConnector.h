#pragma once
//
// Created by admin on 13.04.2025.
//

#ifndef KYRSOVAIA_DBCONNECTOR_H
#define KYRSOVAIA_DBCONNECTOR_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

class DbConnector {
    static DbConnector* current;
    static int count;
    DbConnector(std::string &&host, std::string &&nameUsser, std::string &&paswword);
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    bool isConnect;

public:
    DbConnector(DbConnector* s) = delete;
    static DbConnector* getInstance(std::string &&host, std::string &&nameUsser, std::string &&paswword);
    ~DbConnector();
    void request(std::string &&sql, std::string &&nameDb);
    sql::ResultSet* getRes();
    bool getIsConnect();
    
};


#endif //KYRSOVAIA_DBCONNECTOR_H

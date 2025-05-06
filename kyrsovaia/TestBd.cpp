#include "Dbconnector.h"


#define TEST_CHECK(condition) \
    if (!(condition)) { \
        std::cerr << "Error(" << __FILE__ << ":" << __LINE__ << "): " << std::endl; \
        return 1; \
    }

int testDdConnect() {

    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");

    con->request("TRUNCATE TABLE passenger", "airport_test");
    con->request("TRUNCATE TABLE arrivedpassenger", "airport_test");
    con->request("TRUNCATE TABLE abroad", "airport_test");

    std::string sql = "INSERT INTO abroad(name, surname, thirdname, pasportData) VALUES('Svtlana', 'Smirnova', 'Ivanovna', '8001926630')";
    con->request(std::move(sql), "airport_test");

    sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexsey', 'Sitnikov', 'Pavlovich', '1214', 1234, '1419789345', 1)";
    con->request(std::move(sql), "airport_test");

    sql = "INSERT INTO arrivedpassenger(name, surname, thirdname, flightnumber, pasportData) VALUES('Maria', 'Smirnova', 'Alexandrovna', '3314', '4460826678')";
    con->request(std::move(sql), "airport_test");

    con->request("SELECT COUNT(*) AS total FROM passenger;", "airport_test");
    int ans = -1;
    if (con->getRes() != nullptr) {
        if (con->getRes()->next()) {
            ans = con->getRes()->getInt("total");
        }
    }

    TEST_CHECK(ans == 1)

    con->request("SELECT COUNT(*) AS total FROM abroad;", "airport_test");
    if (con->getRes() != nullptr) {
        if (con->getRes()->next()) {
            ans = con->getRes()->getInt("total");
        }
    }
    TEST_CHECK(ans == 1)

    con->request("SELECT COUNT(*) AS total FROM arrivedpassenger;", "airport_test");
    if (con->getRes() != nullptr) {
        if (con->getRes()->next()) {
            ans = con->getRes()->getInt("total");
        }
    }
    TEST_CHECK(ans == 1)
        return 0;
}

int testSelect() {
    DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");

    con->request("TRUNCATE TABLE passenger", "airport_test");

    std::string sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexsey', 'Sitnikov', 'Pavlovich', '1214', 1234, '1419789345', 1)";
    con->request(std::move(sql), "airport_test");

    sql = "SELECT name FROM passenger WHERE pasportData = '1419789345'";
    con->request(std::move(sql), "airport");
    std::string name = "";
    if (con->getRes()->next()) {
        name = con->getRes()->getString("name");
    }
    TEST_CHECK(name == "Alexsey");
    return 0;
}

int testBd() {
    
    return testDdConnect() + testSelect();
}

int testContainer();
int mainTest() {
    return testBd() + testContainer();
}
#include "pch.h"

#include "../kyrsovaia/DbConnector.h"
#include "../kyrsovaia/DbConnector.cpp"

#include "../kyrsovaia/Flight.h"
#include "../kyrsovaia/Flight.cpp"
TEST(TestCaseName, TestName) {
    /*DbConnector* con = DbConnector::getInstance("tcp://127.0.0.1:3306", "root", "777809");

    con->request("TRUNCATE TABLE passenger", "airport_test");
  

    std::string sql = "INSERT INTO passenger(name, surname, thirdname, flightnumber, numberTicket, pasportData, baggage) \
        \VALUES('Alexsey', 'Sitnikov', 'Pavlovich', '1214', 1234, '1419789345', 1)";
    con->request(std::move(sql), "airport_test");

   
    con->request("SELECT COUNT(*) AS total FROM passenger;", "airport_test");
    int ans = -1;
    if (con->getRes() != nullptr) {
        if (con->getRes()->next()) {
            ans = con->getRes()->getInt("total");
        }
    }*/

    Flight f(12312, 184, true);

    /*TEST_CHECK(f.getAbroadStat() == true);
    TEST_CHECK(f.getNumber() == 12312);
    TEST_CHECK(f.getSeatNumber() == 1);*/

    EXPECT_TRUE(f.getAbroadStat() );
        
}
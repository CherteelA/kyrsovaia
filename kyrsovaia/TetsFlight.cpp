#include <iostream>
#define TEST_CHECK(condition) \
    if (!(condition)) { \
        std::cerr << "Error(" << __FILE__ << ":" << __LINE__ << "): " << std::endl; \
        return 1; \
    }
#include "Flight.h"


int testCreatFlight() {
    Flight f(12312, 184, true);

    TEST_CHECK(f.getAbroadStat() == true);
    TEST_CHECK(f.getNumber() == 12312);
    TEST_CHECK(f.getSeatNumber() == 1);
    return 0;
}

int testFlightContainerGetAbroad() {
    Flight f1(12312, 184, true);
    Flight f2(12421, 123, true);
    Flight f3(54365, 98, true);

    FlightsContainer con;

    con.addFlight(f1);
    con.addFlight(f2);
    con.addFlight(f3);

    TEST_CHECK(con.getStatAbroad(12312) == true);
    TEST_CHECK(con.getStatAbroad(12421) == true);
    TEST_CHECK(con.getStatAbroad(54365) == true);
    return 0;
}

int testFlightContainerSeatNumber() {
    Flight f1(12312, 184, true);
    

    FlightsContainer con;

    con.addFlight(f1);

    TEST_CHECK(con.getSeatNumber(12312) == 1);
    TEST_CHECK(con.getSeatNumber(12312) == 2);
    TEST_CHECK(con.getSeatNumber(12312) == 3);
    return 0;
}

int testContainer() {
    return testCreatFlight() + testFlightContainerSeatNumber() + testFlightContainerGetAbroad();
}
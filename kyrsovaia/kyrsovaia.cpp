#include <iostream>

#include "Passenger.h"

#include "DbConnector.h"



int main() {
    addTestData();
    FlightsContainer cc;
    Flight t(1214, 180);
    cc.addFlight(t);


    PassengerFactory* factory = new CreatDepartingPassenger;

    Passenger* pas = factory->createPassenger("Alexsey", "Sitnikov", "Pavlovich", true, true, true, "1419789345");

    DepartingPassenger* pasDep = (DepartingPassenger*)pas;

    pasDep->checkInPassenger();
    pasDep->checkPassenger();
    pasDep->pasportControle();
    std::cout << pasDep->getStatus();
    delete factory;
    system("pause");
    return 0;
}





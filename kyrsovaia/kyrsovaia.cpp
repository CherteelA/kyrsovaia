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

    PassengerFactory* factory2 = new CreatArrivingPassenger;
    Passenger* pas2 = factory2->createPassenger("Ekaterina", "Smirnova", "Alexeevna", true, true, true, "9819898220");

    ArrivingPassenger* pasDep2 = (ArrivingPassenger*)pas2;
    pasDep2->checkInPassenger();
    pasDep2->pasportControle();
    std::cout << pasDep2->getStatus();


    delete factory;
    system("pause");
    return 0;
}





#include <iostream>

#include "Passenger.h"

#include "DbConnector.h"
#include <Windows.h>
#include "Service.h"
#include "Status.h"


typedef struct title{
    std::string name;
    std::string surname;
    std::string thirdname;
    bool baggage;
    bool carryOn;
    std::string pasport;
}title;

title getData() {
    std::cout << "Введите фио, 1 если есть багаж, 0 если нет, 1 если есть ручная кладь, 0 если нет, и паспортные данные\n";
    title temp;
    std::cin >> temp.surname >> temp.name >> temp.thirdname;
    int flag;
    std::cin >> flag;
    temp.baggage = flag == 1 ? true : false;
    std::cin >> flag;
    temp.carryOn = flag == 1 ? true : false;
    std::cin >> temp.pasport;
    return temp;
}

void departing(DepartingService &service, bool* stop){
    while (true) {
        if (service.getSizeCheckInQueue() > 0) {
            service.checkInPassenger();
            std::cout << 1;
        }
        if (service.getSizeCheckPassengerQueue() > 0) {
            service.checkPassenger();
            std::cout << 1;
        }
        if (service.getSizePasportControleQueue() > 0) {
            service.PasportControlPassenger();
            std::cout << 1;
        }
        if (*stop) {
            break;
        }
    }
}

void arriving(ArrivingService &service, bool *stop) {
    while (true) {
        if (service.getSizeCheckInQueue() > 0) {
            service.checkInPassenger();
        }
        if (service.getSizePasportControleQueue() > 0) {
            service.PasportControlPassenger();
        }
        if (*stop) {
            break;
        }
    }
}


int main() {
    SetConsoleOutputCP(1251);
    
    addTestData();

    DepartingService departingService;
    ArrivingService arrivingService;
    
    bool stop = false;
    std::thread depar(departing, std::ref(departingService), &stop);
    std::thread arrived(arriving, std::ref(arrivingService), &stop);


    std::string comand = "help";
    PassengerFactory* factory = new CreatDepartingPassenger;
    Passenger* passenger;

    Status stat;

   

    while (true) {
        if (comand == "help") {
            std::cout << "Доступные команды:\nhelp просмотр доступных команд\nstatus просмотр статуса\ndeparting пассажир на вылет\narriving прилетевший пассажир\nexit выход\n\n";
        }
        else if (comand == "status") {
            stat.printStatus();
        }
        else if (comand == "departing") {
            title temp = getData();
            passenger = factory->createPassenger(std::move(temp.name), std::move(temp.surname), std::move(temp.thirdname), std::move(temp.baggage), std::move(temp.carryOn), std::move(temp.pasport));
            if (DepartingPassenger* dp = dynamic_cast<DepartingPassenger*>(passenger)) {
                departingService.addPassengber(*dp);
                stat.addPassenger(dp);
            }
        }
        else if (comand == "arriving") {
            title temp = getData();
            passenger = factory->createPassenger(std::move(temp.name), std::move(temp.surname), std::move(temp.thirdname), std::move(temp.baggage), std::move(temp.carryOn), std::move(temp.pasport));
            if (ArrivingPassenger* ap = dynamic_cast<ArrivingPassenger*>(passenger)) {
                arrivingService.addPassengber(*ap);
                stat.addPassenger(ap);
            }
        }
        else if (comand == "exit") {
            stop = true;
            break;
        }
        else{
            std::cout << "Команда не распознана\n";
        }

        std::cin >> comand;

    }
    delete factory;
    
    depar.join();
    arrived.join();
    system("pause");
    return 0;
}




//addTestData();
//FlightsContainer cc;
//Flight t(1214, 180);
//cc.addFlight(t);
//
//
//PassengerFactory* factory = new CreatDepartingPassenger;
//
//Passenger* pas = factory->createPassenger("Alexsey", "Sitnikov", "Pavlovich", true, true, true, "1419789345");
//
//DepartingPassenger* pasDep = (DepartingPassenger*)pas;
//
//pasDep->checkInPassenger();
//pasDep->checkPassenger();
//pasDep->pasportControle();
//std::cout << pasDep->getStatus();
//
//PassengerFactory* factory2 = new CreatArrivingPassenger;
//Passenger* pas2 = factory2->createPassenger("Ekaterina", "Smirnova", "Alexeevna", true, true, true, "9819898220");
//
//ArrivingPassenger* pasDep2 = (ArrivingPassenger*)pas2;
//pasDep2->checkInPassenger();
//pasDep2->pasportControle();
//std::cout << pasDep2->getStatus();
//
//
//delete factory;
#include <iostream>

#include "Passenger.h"

#include "DbConnector.h"
#include <Windows.h>
#include "Service.h"
#include "Status.h"

int mainTest();

typedef struct title{
    std::string name;
    std::string surname;
    std::string thirdname;
    bool baggage;
    bool carryOn;
    std::string pasport;
}title;

title getData(bool *flag) {
    
    title temp;
    std::cout << "\t";
    std::cin >> temp.surname;
    if (temp.surname == "exit") {
        *flag = false;
        return temp;
    }
    std::cin >> temp.name >> temp.thirdname;
    int data;
    std::cin >> data;
    temp.baggage = data == 1 ? true : false;
    std::cin >> data;
    temp.carryOn = data == 1 ? true : false;
    std::cin >> temp.pasport;
    return temp;
}

void departing(DepartingService* service, bool* stop){
    while (true) {
        if (service->getSizeCheckInQueue() > 0) {
            service->checkInPassenger();
           
        }
        if (service->getSizeCheckPassengerQueue() > 0) {
            service->checkPassenger();
            
        }
        if (service->getSizePasportControleQueue() > 0) {
            service->PasportControlPassenger();
            
        }
        if (*stop) {
            break;
        }
    }
}

void arriving(ArrivingService* service, bool *stop) {
    while (true) {
        if (service->getSizeCheckInQueue() > 0) {
            service->checkInPassenger();
            
        }
        if (service->getSizePasportControleQueue() > 0) {
            service->PasportControlPassenger();
            
        }
        if (*stop) {
            break;
        }
    }
}


int main() {
    if (mainTest() != 0) {
        std::cout << "Tests failed\n";
        system("pause");
        return 0;
    }
    

    SetConsoleOutputCP(1251);
    
    addTestData();

    DepartingService departingService;
    ArrivingService arrivingService;
    
    bool stop = false;
    std::thread depar(departing, &departingService, &stop);
    std::thread arrived(arriving, &arrivingService, &stop);


    std::string comand = "help";
    PassengerFactory* factoryDeparting = new CreatDepartingPassenger;
    PassengerFactory* factoryArriving = new CreatArrivingPassenger;
    Passenger* passenger;

    Status stat;

    while (true) {
        if (comand == "help") {
            std::cout << "��������� �������:\nhelp �������� ��������� ������\nstatus �������� �������\ndeparting �������� �� �����\narriving ����������� ��������\nflight �������� ����\nshowFlights ������� ��� �����\nexit �����\n\n";
        }
        else if (comand == "status") {
            stat.printStatus();
        }
        else if (comand == "departing") {
            std::cout << "menu/departing ������� ���, 1 ���� ���� �����, 0 ���� ���, 1 ���� ���� ������ �����, 0 ���� ���, � ���������� ������\n������� exit ��� ������\n";
            bool isEnter = true;
            while (true) {
                title temp = getData(&isEnter);
                if (!isEnter) {
                    break;
                }
                passenger = factoryDeparting->createPassenger(std::move(temp.name), std::move(temp.surname), std::move(temp.thirdname), std::move(temp.baggage), std::move(temp.carryOn), std::move(temp.pasport));
                if (DepartingPassenger* dp = dynamic_cast<DepartingPassenger*>(passenger)) {
                    departingService.addPassengber(dp);
                    stat.addPassenger(dp);
                }
            }
        }
        else if (comand == "arriving") {
            std::cout << "menu/arriving ������� ���, 1 ���� ���� �����, 0 ���� ���, 1 ���� ���� ������ �����, 0 ���� ���, � ���������� ������\n������� exit ��� ������\n";
            bool isEnter = true;
            while (true) {
                title temp = getData(&isEnter);
                if (!isEnter) {
                    break;
                }
                passenger = factoryArriving->createPassenger(std::move(temp.name), std::move(temp.surname), std::move(temp.thirdname), std::move(temp.baggage), std::move(temp.carryOn), std::move(temp.pasport));
                if (ArrivingPassenger* ap = dynamic_cast<ArrivingPassenger*>(passenger)) {
                    arrivingService.addPassengber(ap);
                    stat.addPassenger(ap);
                }
            }
        }
        else if (comand == "flight") {
            std::cout << "menu/flight �������� ����, ������� ����� �����, ���������� ����, 1 ���� �� ������� ��� 0 ���� ������ ������\n��� ������ ������� exit\n";
          
            std::string numb;
            std::string size;
            std::string abroadStatus;
            FlightsContainer conteiner;
            while(true) {
                std::cout << "\t";
                std::cin >> numb;
                if (numb == "exit") {
                    break;
                }
                std::cin >> size >> abroadStatus;

                Flight newFlight(std::stoi(numb), std::stoi(size), abroadStatus == "1" ? true : false);
                conteiner.addFlight(newFlight);
            }
        }
        else if (comand == "showFlights") {
            FlightsContainer conteiner;
            conteiner.showFlights();
        }
        else if (comand == "exit") {
            stop = true;
            break;
        }
        else if (comand == "cls" || comand == "clear") {
            system("cls");
        }
        else{
            std::cout << "������� �� ����������\n";
        }
        std::cout << "menu/";
        std::cin >> comand;

    }
    delete factoryDeparting;
    delete factoryArriving;
    depar.join();
    arrived.join();
    
    return 0;
}



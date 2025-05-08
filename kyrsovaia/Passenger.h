#pragma once
//
// Created by admin on 13.04.2025.
//

#ifndef KYRSOVAIA_PASSENGER_H
#define KYRSOVAIA_PASSENGER_H
#include <iostream>
#include <string>
#include "DbConnector.h"
#include "Flight.h"

class Passenger {
public:
    virtual std::string getName() = 0;
    virtual std::string getSurname() = 0;
    virtual std::string getThirdname() = 0;
    virtual int getNumberFlight() = 0;
    virtual std::string getPasportData() = 0;
    virtual int getStatus() = 0;
    virtual bool getAbroadStatus() = 0;
    virtual int getType() = 0; //0 departing, 1 arriving
};





class ArrivingPassenger : public Passenger {
    std::string name;
    std::string surname;
    std::string thirdName;
    bool baggage;
    bool carryon;
    short status;//0 - перед регистрацией, 1 - зарегистрированный, 2 - проверенный, 3 - прошёл паспортный контроль
    int numberFlight;
    std::string pasportData;
    bool abroad;
public:
    ArrivingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, std::string& pasport);
    int pasportControle();
    int checkInPassenger();
    std::string getName() override;
    std::string getSurname() override;
    std::string getThirdname() override;
    int getNumberFlight() override;
    std::string getPasportData() override;
    int getStatus() override;
    bool getAbroadStatus() override;
    int getType() override;
};








class DepartingPassenger : public Passenger {
    std::string name;
    std::string surname;
    std::string thirdName;
    bool baggage;
    bool carryon;
    short status;//0 - перед регистрацией, 1 - зарегистрированный, 2 - проверенный, 3 - прошёл паспортный контроль
    int numberTicket;
    int numberSeat;
    int numberFlight;
    std::string pasportData;
    bool abroad;
public:
    DepartingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, std::string& pasport);
    int checkInPassenger();
    int checkPassenger();
    int pasportControle();
    std::string getName() override;
    std::string getSurname() override;
    std::string getThirdname() override;
    int getNumberFlight() override;
    std::string getPasportData() override;
    int getStatus() override;
    bool getAbroadStatus() override;
    int getType() override;
};



class PassengerFactory {
public:
    virtual Passenger* createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, std::string&& pasport) = 0; // Метод для создания пассажира
    virtual ~PassengerFactory() = default; // Виртуальный деструктор
};


class  CreatArrivingPassenger : public PassengerFactory {
public:
    Passenger* createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, std::string&& pasport);
};


class CreatDepartingPassenger : public PassengerFactory {
public:
    Passenger* createPassenger(std::string&& name, std::string&& surname, std::string&& thirdName, bool&& baggage, bool&& carryOn, std::string&& pasport);
};


void addTestData();
#endif //KYRSOVAIA_PASSENGER_H

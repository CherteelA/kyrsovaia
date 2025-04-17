#pragma once
//
// Created by admin on 13.04.2025.
//

#ifndef KYRSOVAIA_PASSENGER_H
#define KYRSOVAIA_PASSENGER_H
#include <iostream>
#include <string>

class Passenger {
public:
    virtual std::string getName() = 0;
    virtual std::string getSurname() = 0;
    virtual std::string getThirdname() = 0;
    virtual int getTicketNumber() = 0; // ��������� ������ ������
    virtual int getSeatNumber() = 0; // ��������� ������ �����
};

class ArrivingPassenger : public Passenger {

public:
    ArrivingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, bool& abroad);
    void pasportControle();
};

class DepartingPassenger : public Passenger {
    std::string name;
    std::string surname;
    std::string thirdName;
    bool baggage;
    bool carryon;
    short status;//0 - ����� ������������, 1 - ������������������, 2 - �����������, 3 - ������ ���������� ��������
    bool abroad;
    int numberTicket;
    int numberSeat;
    int numberFlight;
public:
    DepartingPassenger(std::string& name, std::string& surname, std::string& thirdName, bool& baggage, bool& carryOn, bool& abroad, int numberFlight);
    void checkInPassenger();
    void checkPassenger();
    void pasportControle();
    std::string getName() override;
    std::string getSurname() override;
    std::string getThirdname() override;
    int getTicketNumber() override; // ��������� ������ ������
    int getSeatNumber() override; // ��������� ������ �����
};

class PassengerFactory {
public:
    virtual Passenger* createPassenger(std::string name, std::string surname, std::string thirdname, bool baggage, bool carryon) = 0; // ����� ��� �������� ���������
    virtual ~PassengerFactory() = default; // ����������� ����������
};

class  CreatArrivingPassenger : public PassengerFactory {
public:
    ArrivingPassenger* createPassenger(std::string name, std::string surname, std::string thirdname, bool baggage, bool carryon);
};

class CreatDepartingPassenger : public PassengerFactory {
public:
    DepartingPassenger* createPassenger(std::string name, std::string surname, std::string thirdname, bool baggage, bool carryon);
};


#endif //KYRSOVAIA_PASSENGER_H

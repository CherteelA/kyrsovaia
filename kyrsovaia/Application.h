#pragma once

#include <iostream>
#include "Passenger.h"
#include "DbConnector.h"
#include <Windows.h>
#include "Service.h"
#include "Status.h"

int mainTest();

typedef struct title {
    std::string name;
    std::string surname;
    std::string thirdname;
    bool baggage;
    bool carryOn;
    std::string pasport;
}title;

class Application {
public:
    title getData(bool* flag);
    void departing(DepartingService* service, bool* stop);
    void arriving(ArrivingService* service, bool* stop);
    int mainProgram();
};
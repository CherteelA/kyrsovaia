#include "Status.h"


Status::~Status() {
	for (Passenger* i : passengers) {
		if (i != nullptr) {
			delete i;
		}
	}
}

void Status::addPassenger(Passenger* newPassenger) {
	passengers.push_back(newPassenger);
}


void Status::printStatus() {
	for (Passenger* i : passengers) {
		if (i != nullptr) {
			std::cout << i->getSurname() << " " << i->getName() << " " << i->getThirdname() << std::endl;

			switch (i->getStatus()){
			case 0:
				if (i->getType() == 0) {
					std::cout << "Ожидает регистрации";
				}
				else {
					std::cout << "Ожидает прилёта";
				}
				break;
			case 1:
				if (i->getType() == 0) {
					std::cout << "Ожидает досмотр";
				}
				else {
					if (i->getAbroadStatus()) {
						std::cout << "Ожидает паспортный контроль";
					}
					else {
						std::cout << "Прилетел";
					}
				}
				break;
			case 2:
				if (i->getAbroadStatus()) {
					std::cout << "Ожидает паспортный контроль";
				}
				else {
					std::cout << "Ожидает вылета";
				}
				break;
			case 3:
				if (i->getType() == 0) {
					std::cout << "Ожидает вылета";
				}
				else {
					std::cout << "Прилетел";
				}
				break;
			}
			std::cout << std::endl << std::endl;
		}
	}
}
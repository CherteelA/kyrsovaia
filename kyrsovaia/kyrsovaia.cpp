#include <iostream>
#include "DbConnector.h"

DbConnector* DbConnector::current = nullptr;
int DbConnector::count = 0;

int main() {
    DbConnector* con = DbConnector::getInstance();
   
    con->creatConn("tcp://127.0.0.1:3306", "root", "777809", "airport");

    std::string t = "SELECT name FROM passenger";

    con->request(t);

    try {
        if (con->getRes() != nullptr) {
            while (con->getRes()->next()) {
                        // Извлекаем данные по именам столбцов      
                        std::string name = con->getRes()->getString("name");
                        // Выводим данные на экран
                        std::cout << "Name: " << name << std::endl;
                    }
        }
    }
    catch (std::exception& e) {
        e.what();
    }


    system("pause");
    return 0;
}

//
// Created by timas on 15.12.2021.
//

#include <iostream>
#include "userInterface.hpp"
#include "operation.hpp"

UserInterface::UserInterface() {
    operation = std::make_unique<Operation>();
}

void UserInterface::startOperation() {
    std::cout << "Начало операции. " << std::endl;
    while (true) {
        std::cout << "Введите миссию для выполнения.\n"
                     "цифра 1 - Dive, цифра 2 - Lift, цифра 3 - Move, цифра 4 - Return, \n"
                     "цифра 5 - Показать текущий ход операции" << std::endl;
        int MissionType;
        std::cin >> MissionType;
        if (NewAction(MissionType)) {
            break;
        }
    }
    std::cout << "Конец операции, данные об операции записаны в txt файл.";
}

bool UserInterface::NewAction(int missionType) {
    bool stop = false;
    std::unique_ptr<IMission> mission;
    if (missionType == 1) {
        int deepSetting; // 0 - датчик глубины (глубина) ; 1 - эхолот (отстояние)
        int deepValue;
        int deepType; // 0 - спираль; 1 - вертикальные движения
        std::cout << "Введите способ задания глубины (0 - датчик глубины (глубина) ; 1 - эхолот (отстояние)): " << std::endl;
        while (true) {
            std::cin >> deepSetting;
            if (deepSetting != 0 && deepSetting != 1) {
                std::cout << "Неверный способ задания глубины. Введите способ задания глубины ещё раз.";
                std::cin >> deepSetting;
            } else {
                break;
            }
        }
        std::cout << "Введите глубину погружения: " << std::endl;
        while (true) {
            std::cin >> deepValue;
            if (deepValue <= 0) {
                std::cout << "Неверная глубина погружения(отстояния). Глубина погружения(отстояния) - положительное число.";
                std::cin >> deepValue;
            } else {
                break;
            }
        }
        std::cout << "Введите тип погружения (0 - по спирали; 1 - вертикальные движения): " << std::endl;
        while (true) {
            std::cin >> deepType;
            if (deepType != 0 && deepType != 1) {
                std::cout << "Неверный тип погружения. Введите тип погружения ещё раз.";
                std::cin >> deepType;
            } else {
                break;
            }
        }
        mission = std::make_unique<Dive>(deepSetting, deepValue, deepType, operation->GetCurrentZ());
    }
    operation->SetMission(std::move(mission));
    operation->Do();
    return stop;
}

void UserInterface::ShowAllMissions() {

}

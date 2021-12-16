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
        std::cout << "Введите задачу для выполнения.\n"
                     "цифра 1 - добавление мисси Dive;\nцифра 2 - добавление миссии Lift;\nцифра 3 - Добавление миссии Move;\n"
                     "цифра 4 - добавление миссии Return;\n"
                     "цифра 5 - Показать текущий ход операции;\nцифра 6 - поменять миссии местами;\n"
                     "цифра 7 - удаление задачи;\nцифра 8 - вставка новой задачи.\n"
                     "цифра 9 - добавление миссии из удалённых миссий" << std::endl;
        int MissionType;
        std::cin >> MissionType;
        if (MissionType >= 0 && MissionType < 10) {
            if (NewAction(MissionType)) {
                break;
            }
        } else {
            std::cout << "Некорректное действие" << std::endl;
        }
    }
    std::cout << "Конец операции.";
}

bool UserInterface::NewAction(int eventType) {
    bool stop = false;
    if (eventType == SHOW_MISSIONS) {
        operation->ShowOperation();
        return stop;
    } else if (eventType == SWAP_MISSIONS) {
        operation->ShowOperation();
        std::cout << "Выберите две миссии, чтобы поменять их местами (по индексу из списка)." << std::endl;
        size_t idx1, idx2;
        std::cin >> idx1 >> idx2;
        operation->SwapMissions(idx1, idx2);
        return stop;
    } else if (eventType == DELETE_MISSION) {
        operation->ShowOperation();
        std::cout << "Выберите задачу для удаления." << std::endl;
        size_t idx;
        std::cin >> idx;
        operation->DeleteMission(idx);
        return stop;
    } else if (eventType == INSERT_MISSION) {
        operation->ShowOperation();
        std::cout << "Выберите куда вставить новую задачу (индекс)." << std::endl;
        size_t idx;
        size_t operationLen = operation->getOperationLen();
        std::cin >> idx;
        std::cout << "Выберите тип миссии.\nцифра 1 - добавление мисси Dive;\n"
                     "цифра 2 - добавление миссии Lift;\nцифра 3 - Добавление миссии Move;\n"
                     "цифра 4 - добавление миссии Return;\n";
        while (true) {
            std::cin >> eventType;
            if (eventType == 4 && idx != operationLen) {
                std::cout << "Нельзя вставить миссию Return не в конец операции, введите тип миссии ещё раз" << std::endl;
            }
            if (eventType >= 0 && eventType < 5) {
                operation->InsertMission(idx, std::move(NewMission(eventType, stop)));
                return stop;
            } else {
                std::cout << "Некорректный тип мисси, введите тип миссии ещё раз." << std::endl;
            }
        }
    } else if (eventType == PUSH_DELETED_MISSION) {
        size_t operationLen = operation->getDeletedOperationLen();
        if (operationLen == 0) {
            std::cout << "Удалённых задач нет." << std::endl;
            return stop;
        }
        operation->ShowDeletedOperation();
        std::cout << "Выберите задачу для вставки." << std::endl;
        size_t idx;
        std::cin >> idx;
        operation->PushDeletedMission(idx);
        return stop;
    }
    operation->SetMission(std::move(NewMission(eventType, stop)));
    operation->Do();
    operation->UpdateFileWithOperationData();
    return stop;
}

std::unique_ptr<IMission> UserInterface::NewMission(int missionType, bool &stop) {
    std::unique_ptr<IMission> mission;
    if (missionType == DIVE_MISSION || missionType == LIFT_MISSION) {
        int deepSetting; // 0 - датчик глубины (глубина) ; 1 - эхолот (отстояние)
        int deepValue;
        int deepType; // 0 - спираль; 1 - вертикальные движители

        std::cout << "Введите способ задания глубины (0 - датчик глубины (глубина) ; 1 - эхолот (отстояние)): " << std::endl;
        while (true) {
            std::cin >> deepSetting;
            if (deepSetting != 0 && deepSetting != 1) {
                std::cout << "Неверный способ задания глубины. Введите способ задания глубины ещё раз." << std::endl;
                std::cin >> deepSetting;
            } else {
                break;
            }
        }

        std::cout << "Введите глубину погружения(отстояния): " << std::endl;
        std::cin >> deepValue;

        std::cout << "Введите тип погружения (0 - по спирали; 1 - вертикальные движители): " << std::endl;
        while (true) {
            std::cin >> deepType;
            if (deepType != 0 && deepType != 1) {
                std::cout << "Неверный тип погружения. Введите тип погружения ещё раз." << std::endl;
                std::cin >> deepType;
            } else {
                break;
            }
        }
        if (missionType == DIVE_MISSION) {
            mission = std::make_unique<Dive>(deepSetting, deepValue, deepType);
        } else {
            mission = std::make_unique<Lift>(deepSetting, deepValue, deepType);
        }
    } else if (missionType == MOVE_MISSION) {
        int newX;
        int newY;
        int moveType; // 0 - выход в точку; 1 - движение вдоль прямой
        int deepType; // 0 - на постоянной глубине; 1 - на постоянном отстоянии от дна
        std::cout << "Введите тип выхода (0 - выход в точку ; 1 - движение вдоль прямой): " << std::endl;
        while (true) {
            std::cin >> moveType;
            if (moveType != 0 && moveType != 1) {
                std::cout << "Неверный тип выхода. Введите тип выхода ещё раз." << std::endl;
                std::cin >> moveType;
            } else {
                break;
            }
        }

        std::cout << "Введите тип выхода(0 - на постоянной глубине; 1 - на постоянном отстоянии от дна): " << std::endl;
        while (true) {
            std::cin >> deepType;
            if (deepType != 0 && deepType != 1) {
                std::cout << "Неверный тип выхода. Введите тип выхода ещё раз." << std::endl;
                std::cin >> deepType;
            } else {
                break;
            }
        }

        std::cout << "Введите координату X: " << std::endl;
        std::cin >> newX;

        std::cout << "Введите координату Y: " << std::endl;
        std::cin >> newY;
        mission = std::make_unique<Move>(newX, newY, moveType, deepType);
    } else if (missionType == RETURN_MISSION) {
        mission = std::make_unique<Return>();
        stop = true;
    }
    return std::move(mission);
}

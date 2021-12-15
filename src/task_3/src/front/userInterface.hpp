//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_USERINTERFACE_HPP
#define TASK_3_USERINTERFACE_HPP

#include <memory>

class Operation;

class UserInterface {
private:
    std::unique_ptr<Operation> operation;

    bool NewAction(int missionType);

    void ShowAllMissions();

public:
    UserInterface();

    void startOperation();
};

#endif //TASK_3_USERINTERFACE_HPP

//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_USERINTERFACE_HPP
#define TASK_3_USERINTERFACE_HPP

#include <memory>

#define DIVE_MISSION 1
#define LIFT_MISSION 2
#define MOVE_MISSION 3
#define RETURN_MISSION 4
#define SHOW_MISSIONS 5

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

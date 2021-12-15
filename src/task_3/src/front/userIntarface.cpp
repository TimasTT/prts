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
    std::cout << "Начало миссии" << std::endl;
}

void UserInterface::NewMission(const std::string &missionName) {

}

void UserInterface::ShowAllMissions() {

}

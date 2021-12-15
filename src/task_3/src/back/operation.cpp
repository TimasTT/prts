//
// Created by timas on 15.12.2021.
//

#include <iostream>
#include "operation.hpp"
#include "mission.hpp"

void Operation::Do() {
    if (currentMission->Move(position)) {
        missionsList.push_back(std::move(currentMission));
        return;
    }
    std::cout << "Миссия невозможна." << std::endl;
}

void Operation::CreateFileWithOperationData() const {

}

void Operation::SetMission(std::unique_ptr<IMission> mission) {
    currentMission = std::move(mission);
}

void Operation::ShowOperation() const {
    int missionIndex = 0;
    for (const auto &mission : missionsList) {
        std::cout << "Миссия " << missionIndex++ << std::endl;
        std::cout << mission->GetMissionData() << std::endl;
    }
}

size_t Operation::getOperationLen() const {
    return missionsList.size();
}


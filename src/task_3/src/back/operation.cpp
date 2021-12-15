//
// Created by timas on 15.12.2021.
//

#include "operation.hpp"
#include "mission.hpp"

Operation::Operation(): currentX(0), currentY(0), currentZ(0) {
}

void Operation::Do() {
    if (currentMission->Check()) {
        missionsList.push_back(std::move(currentMission));
    }

}

void Operation::CreateFileWithOperationData() const {

}

void Operation::SetMission(std::unique_ptr<IMission> mission) {
    currentMission = std::move(mission);
}

int Operation::GetCurrentX() const {
    return currentX;
}

int Operation::GetCurrentY() const {
    return currentY;
}

int Operation::GetCurrentZ() const {
    return currentZ;
}


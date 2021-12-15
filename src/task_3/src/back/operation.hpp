//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_OPERATION_HPP
#define TASK_3_OPERATION_HPP

#include <string>
#include <vector>

#include "mission.hpp"

class Operation {
private:
    std::vector<std::unique_ptr<IMission>> missionsList;

    std::unique_ptr<IMission> currentMission;

    int currentX;
    int currentY;
    int currentZ;

public:
    Operation();

    ~Operation() = default;

    void Do();

    void CreateFileWithOperationData() const;

    void SetMission(std::unique_ptr<IMission> mission);

    int GetCurrentX() const;

    int GetCurrentY() const;

    int GetCurrentZ() const;
};

#endif //TASK_3_OPERATION_HPP

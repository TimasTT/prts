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

    int currentX;
    int currentY;
    int currentZ;

public:
    Operation();

    ~Operation() = default;

    void Do();

    void CreateFileWithOperationData();
};

#endif //TASK_3_OPERATION_HPP

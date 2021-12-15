//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_OPERATION_HPP
#define TASK_3_OPERATION_HPP

#include <string>
#include <vector>

#include "mission.hpp"
#include "position.hpp"

class Operation {
private:
    std::vector<std::unique_ptr<IMission>> missionsList;

    std::unique_ptr<IMission> currentMission;

    Position position;

public:
    Operation() = default;

    ~Operation() = default;

    void Do();

    void CreateFileWithOperationData() const;

    void SetMission(std::unique_ptr<IMission> mission);

    void ShowOperation() const;

    size_t getOperationLen() const;
};

#endif //TASK_3_OPERATION_HPP

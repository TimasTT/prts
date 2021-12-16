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
    std::vector<std::unique_ptr<IMission>> deletedMissionsList;

    std::unique_ptr<IMission> currentMission;

public:
    Operation() = default;

    ~Operation() = default;

    void Do();

    void UpdateFileWithOperationData() const;

    void SetMission(std::unique_ptr<IMission> mission);

    void ShowOperation() const;

    void ShowDeletedOperation() const;

    size_t getOperationLen() const;

    size_t getDeletedOperationLen() const;

    void SwapMissions(size_t idx1, size_t idx2);

    void DeleteMission(size_t idx);

    void InsertMission(size_t idx, std::unique_ptr<IMission> mission);

    void PushDeletedMission(size_t idx);
};

#endif //TASK_3_OPERATION_HPP

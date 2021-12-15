//
// Created by timas on 15.12.2021.
//
#include "mission.hpp"

Dive::Dive(int deepSetting, int deepValue, int deepType)
        : deepSetting(deepSetting), deepValue(deepValue), deepType(deepType), currentDeep(0) {}

const std::string &Dive::GetMissionData() {
    if (missionData.empty()) {
        missionData += "Dive\n";
        if (deepSetting == 0) {
            missionData += "Задание глубины по датчику глубины;\n";
            missionData = missionData + "Глубина погружения: " + std::to_string(deepValue) + ";\n";
        } else {
            missionData += "Задание глубины по эхолоту;\n";
            missionData = missionData + "Отстояние: " + std::to_string(deepValue) + ";\n";
        }
        if (deepType == 0) {
            missionData += "Тип погружения: по спирали;\n";
        } else {
            missionData += "Тип погружения: за счёт вертикальных движителей\n";
        }
        missionData += "Текущая глубина погружения: " + std::to_string(currentDeep) + "\n";
    }
    return missionData;
}

bool Dive::Move(Position& position) {
    unsigned int currentPositionZ = position.GetPositionZ();
    if (deepSetting == 0) {
        if (currentPositionZ + deepValue < maxDeep) {
            position.ChangePositionZ(deepValue);
            currentDeep = position.GetPositionZ();
            return true;
        }
    } else {
        if (currentPositionZ - deepValue > minDeep) {
            position.ChangePositionZ(-deepValue);
            currentDeep = position.GetPositionZ();
            return true;
        }
    }
    return false;
}


Lift::Lift(int deepSetting, int deepValue, int deepType)
        : deepSetting(deepSetting), deepValue(deepValue), deepType(deepType), currentDeep(0) {}

const std::string &Lift::GetMissionData() {
    if (missionData.empty()) {
        missionData += "Lift\n";
        if (deepSetting == 0) {
            missionData += "Задание глубины по датчику глубины;\n";
            missionData = missionData + "Глубина погружения: " + std::to_string(deepValue) + ";\n";
        } else {
            missionData += "Задание глубины по эхолоту;\n";
            missionData = missionData + "Отстояние: " + std::to_string(deepValue) + ";\n";
        }
        if (deepType == 0) {
            missionData += "Тип погружения: по спирали;\n";
        } else {
            missionData += "Тип погружения: за счёт вертикальных движителей\n";
        }
        missionData += "Текущая глубина погружения: " + std::to_string(currentDeep) + "\n";
    }
    return missionData;
}

bool Lift::Move(Position& position) {
    unsigned int currentPositionZ = position.GetPositionZ();
    if (deepSetting == 0) {
        if (currentPositionZ + deepValue < maxDeep) {
            position.ChangePositionZ(deepValue);
            currentDeep = position.GetPositionZ();
            return true;
        }
    } else {
        if (currentPositionZ - deepValue > minDeep) {
            position.ChangePositionZ(-deepValue);
            currentDeep = position.GetPositionZ();
            return true;
        }
    }
    return false;
}

//
// Created by timas on 15.12.2021.
//
#include "mission.hpp"

Dive::Dive(int deepSetting, int deepValue, int deepType)
        : deepSetting(deepSetting), newZ(deepValue), deepType(deepType) {}

const std::string &Dive::GetMissionData() {
    missionData.clear();
    missionData += "Dive\n";
    if (deepSetting == 0) {
        missionData += "Задание глубины по датчику глубины;\n";
        missionData = missionData + "Глубина погружения: " + std::to_string(newZ) + ";\n";
    } else {
        missionData += "Задание глубины по эхолоту;\n";
        missionData = missionData + "Отстояние: " + std::to_string(newZ) + ";\n";
    }
    if (deepType == 0) {
        missionData += "Тип погружения: по спирали;\n\n";
    } else {
        missionData += "Тип погружения: за счёт вертикальных движителей\n\n";
    }
    return missionData;
}

bool Dive::Run() {
    if (newZ <= maxDeep && newZ >= 0) {
        return true;
    }
    return false;
}


Lift::Lift(int deepSetting, int deepValue, int deepType)
        : deepSetting(deepSetting), newZ(deepValue), deepType(deepType) {}

const std::string &Lift::GetMissionData() {
    missionData.clear();
    missionData += "Lift\n";
    if (deepSetting == 0) {
        missionData += "Задание глубины по датчику глубины;\n";
        missionData = missionData + "Глубина погружения: " + std::to_string(newZ) + ";\n";
    } else {
        missionData += "Задание глубины по эхолоту;\n";
        missionData = missionData + "Отстояние: " + std::to_string(newZ) + ";\n";
    }
    if (deepType == 0) {
        missionData += "Тип погружения: по спирали;\n\n";
    } else {
        missionData += "Тип погружения: за счёт вертикальных движителей\n\n";
    }
    return missionData;
}

bool Lift::Run() {
    if (newZ <= maxDeep && newZ >= 0) {
        return true;
    }
    return false;
}


Move::Move(int newX, int newY, int moveType, int deepType)
        : newX(newX), newY(newY), moveType(moveType), deepType(deepType) {}

bool Move::Run() {
    if (newX + moveAccuracy < 5000 && newX + moveAccuracy > -5000) {
        return true;
    }
    return false;
}

const std::string &Move::GetMissionData() {
    missionData.clear();
    missionData += "Move\n";
    if (moveType == 0) {
        missionData += "Выход в точку;\n";
    } else {
        missionData += "Движение вдоль прямой;\n";
    }
    if (deepType == 0) {
        missionData += "Движение на постоянной глубине;\n";
    } else {
        missionData += "Движение на постоянном отстоянии от дна\n";
    }
    missionData = missionData + "Координата X: " + std::to_string(newX) + " с точностью +-" + std::to_string(moveAccuracy) + ";\n";
    missionData = missionData + "Координата Y: " + std::to_string(newY) + " с точностью +-" + std::to_string(moveAccuracy) + ";\n\n";
    return missionData;
}

bool Return::Run() {
    return true;
}

const std::string &Return::GetMissionData() {
    return missionData;
}

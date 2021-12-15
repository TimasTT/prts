//
// Created by timas on 15.12.2021.
//
#include "mission.hpp"

Dive::Dive(int deepSetting, int deepValue, int deepType, int currentDeep)
        : deepSetting(deepSetting), deepValue(deepValue), deepType(deepType), currentDeep(currentDeep) {}

const std::string &Dive::GetMissionData() const {
//    return <#initializer#>;
}

bool Dive::Check() const {
    return true;
}


Lift::Lift(int deepSetting, int deepValue, int deepType, int currentDeep)
        : deepSetting(deepSetting), deepValue(deepValue), deepType(deepType), currentDeep(currentDeep) {}

const std::string &Lift::GetMissionData() const {
//    return <#initializer#>;
}

bool Lift::Check() const {
    return false;
}

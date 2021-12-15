//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_MISSION_HPP
#define TASK_3_MISSION_HPP

#include <string>
#include <memory>

#include "position.hpp"

class IMission {
public:
    virtual ~IMission() = default;

    virtual bool Move(Position& position) = 0;

    virtual const std::string &GetMissionData() = 0;
};

class Dive: public IMission {
private:
    int deepSetting; // 0 -  датчик глубины (глубина) ; 1 - эхолот (отстояние)
    int deepValue;
    int deepType; // 0 - спираль; 1 - вертикальные движители

    unsigned int currentDeep;

    int maxDeep = 100;
    int minDeep = 0;

    std::string missionData;

public:
    Dive() = delete;

    explicit Dive(int deepSetting, int deepValue, int deepType);

    ~Dive() override = default;

    bool Move(Position& position) override;

    const std::string &GetMissionData() override;
};

class Lift: public IMission {
private:
    int deepSetting; // 0 -  датчик глубины (глубина) ; 1 - эхолот (отстояние)
    int deepValue;
    int deepType; // 0 - спираль; 1 - вертикальные движители

    int maxDeep = 100;
    int minDeep = 0;

    unsigned int currentDeep;

    std::string missionData;

public:
    Lift() = delete;

    explicit Lift(int deepSetting, int deepValue, int deepType);

    bool Move(Position& position) override;

    const std::string &GetMissionData() override;
};

#endif //TASK_3_MISSION_HPP

//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_MISSION_HPP
#define TASK_3_MISSION_HPP

#include <string>
#include <memory>

class IMission {
public:
    virtual ~IMission() = default;

    virtual bool Check() const = 0;

    virtual const std::string &GetMissionData() const = 0;
};

class Dive: public IMission {
private:
    int deepSetting; // 0 -  датчик глубины (глубина) ; 1 - эхолот (отстояние)
    int deepValue;
    int deepType; // 0 - спираль; 1 - вертикальные движения

    int currentDeep;

    int maxDeep = 100;
    std::string operation = "Dive";

public:
    Dive() = delete;

    explicit Dive(int deepSetting, int deepValue, int deepType, int currentDeep);

    ~Dive() override = default;

    bool Check() const override;

    const std::string &GetMissionData() const override;
};

class Lift: public IMission {
private:
    int deepSetting; // 0 -  датчик глубины (глубина) ; 1 - эхолот (отстояние)
    int deepValue;
    int deepType; // 0 - спираль; 1 - вертикальные движения

    int currentDeep;

    int maxDeep = 100;
    std::string operation = "Lift";

public:
    Lift() = delete;

    explicit Lift(int deepSetting, int deepValue, int deepType, int currentDeep);

    bool Check() const override;

    const std::string &GetMissionData() const override;
};

#endif //TASK_3_MISSION_HPP

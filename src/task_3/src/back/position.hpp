//
// Created by timas on 15.12.2021.
//

#ifndef TASK_3_POSITION_HPP
#define TASK_3_POSITION_HPP

class Position {
private:
    int positionX;

    int positionY;

    int positionZ;

public:
    Position();

    virtual ~Position() = default;

    int GetPositionX() const;

    int GetPositionY() const;

    int GetPositionZ() const;

    void ChangePositionX(int x);

    void ChangePositionY(int y);

    void ChangePositionZ(int z);
};

#endif //TASK_3_POSITION_HPP

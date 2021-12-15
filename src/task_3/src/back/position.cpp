//
// Created by timas on 15.12.2021.
//

#include "position.hpp"


Position::Position(): positionX(0), positionY(0), positionZ(0) {}

int Position::GetPositionX() const {
    return positionX;
}

int Position::GetPositionY() const {
    return positionY;
}

int Position::GetPositionZ() const {
    return positionZ;
}

void Position::ChangePositionX(int x) {
    positionX += x;
}

void Position::ChangePositionY(int y) {
    positionY += y;
}

void Position::ChangePositionZ(int z) {
    positionZ += z;
}



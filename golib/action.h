#pragma once
#include "point.h"

enum ActionEnum {
    Pass,
    Resign,
    Move
};

class Action {
public:
    virtual ActionEnum getAction() const = 0;
};

class PassAction : public Action {
public:
    ActionEnum getAction() const override { return ActionEnum::Pass; }
};

class ResignAction : public Action {
public:
    ActionEnum getAction() const override { return ActionEnum::Resign; }
};

class MoveAction : public Action {
public:
    MoveAction(const Point& point) : _point(point) {}

    ActionEnum getAction() const override { return ActionEnum::Move; }
    Point getPoint() const { return _point; }

private:
    Point _point;
};

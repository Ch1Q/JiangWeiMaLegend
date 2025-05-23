#pragma once
#include "raylib.h"
#include <string>
class Component2D
{
    private:
    bool Activate = 1;
    public:

    std::string name;
    bool isActivate();
    void setActivate(bool _activate);
    Component2D(std::string _name);
    Component2D(std::string _name, bool _Activate);
    virtual ~Component2D() = default;
    virtual void Start();
    virtual void Update(float _delta);

};

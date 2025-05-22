#pragma once
#include "INode2D.h"
#include "raylib.h"
#include <string>
class Component2D
{
    private:
    
    public:
    std::string name;
    INode2D* parent = nullptr;
    Component2D(/* args */);

    ~Component2D();

};

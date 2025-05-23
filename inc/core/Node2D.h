#pragma once
#include "raylib.h"
#include <vector>
#include "Component2D.h"
#include <string>
class Node2D
{
    Node2D* parentNode = nullptr;
    std::vector<Component2D*> Components;

    public:
    std::string name;
    Node2D(std::string _name);
    ~Node2D();
    
};
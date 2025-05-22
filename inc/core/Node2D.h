#pragma once
#include "raylib.h"
#include <vector>
#include "Component2D.h"
#include "INode2D.h"
#include <string>
#include "IScene.h"
class Node2D : public INode2D
{
    Node2D* parentNode = nullptr;
    

    public:
    IScene2D* inScene = nullptr;
    std::vector<Component2D*> Components;
    Node2D();
    ~Node2D();
    
};
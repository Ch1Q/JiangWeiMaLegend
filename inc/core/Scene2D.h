#pragma once
#include "IScene.h"
#include "Node2D.h"
#include <vector>

class Scene2D : public IScene2D
{
private:
    /* data */
public:
    std::vector<Node2D*> Nodes;
    Scene2D(/* args */);
    ~Scene2D();
};

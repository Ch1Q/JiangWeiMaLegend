#pragma once
#include "Node2D.h"
#include <vector>
#include <unordered_set>
class SceneNode2D : public Node2D
{
private:
    std::unordered_set<std::shared_ptr<SceneNode2D>> Nodes;
    
public:
};

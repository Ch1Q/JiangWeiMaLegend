#pragma once
#include "Node2D.h"
#include <vector>
#include <forward_list>
class Scene2D
{
private:
    std::forward_list<Node2D*> Nodes;
public:
    std::string name;
    
    Scene2D(std::string _name);
    ~Scene2D();
    void AddNode(Node2D* node);
    void DelNode(Node2D* node);
    void GiveNode(Node2D* _node, Scene2D* _scene);
    std::forward_list<Node2D*> GetNodes();
};

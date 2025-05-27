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
    bool isActivate = 0;
    Scene2D(std::string _name);
    Scene2D(std::string _name, bool _Activate);
    ~Scene2D();
    void AddNode(Node2D* _node);
    void DelNode(Node2D* _node);
    void DelNode(std::string _nodeName);
    void GiveNode(Node2D* _node, Scene2D* _scene);
    void GiveNode(std::string _nodeName, Scene2D* _scene);
    Node2D* GetNode(std::string _nodeName);
    std::forward_list<Node2D*> GetNodes();
    void Start();
    void Update(float _delta);
};

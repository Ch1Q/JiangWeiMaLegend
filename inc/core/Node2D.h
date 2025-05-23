#pragma once
#include "raylib.h"
#include <vector>
#include "Component2D.h"
#include <string>
#include <forward_list>

struct transform2D
{
    Vector2 position;
    float rotation;
    Vector2 scale;
    transform2D(Vector2 pos, float rtn, Vector2 scl);
    transform2D();
};

class Scene2D;

class Node2D
{
    Node2D* parentNode = nullptr;
    std::forward_list<Node2D*> SubNodes;
    std::forward_list<Component2D*> Components;
    bool Activate = 1; 
    
    public:
    transform2D transform;
    std::string name;
    Node2D(std::string _name);
    Node2D(std::string _name, bool _Activate);
    Node2D(std::string _name,transform2D _trans);
    ~Node2D();
    bool isActivate();
    void setActivate(bool _activate);
    void AddComponent(Component2D* _comp);
    void DelComponent(Component2D* _comp);
    void DelComponent(std::string _comp);
    void GiveComponent(Component2D* _comp, Node2D* _node);
    void GiveComponent(std::string _comp, Node2D* _node);
    void AddSubNode(Node2D* _node);
    void DelSubNode(Node2D* _node);
    void DelSubNode(std::string _node);
    void GiveSubNode(Node2D* _subnode, Node2D* _toNode);
    void GiveSubNode(std::string _node, Scene2D* _scene);
    std::forward_list<Component2D*> GetComponents();
    std::forward_list<Node2D*> GetSubNodes();
    virtual void Start();
    virtual void Update(float _delta);
    void SubNodesStart();
    void SubNodesUpdate(float _delta);
    void ComponentsStart();
    void ComponentsUpdate(float _delta);
};
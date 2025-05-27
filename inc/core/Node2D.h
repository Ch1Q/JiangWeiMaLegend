#pragma once
#include "raylib.h"
#include <vector>
#include "Component2D.h"
#include <string>
#include <forward_list>
#include <unordered_map>
#include <memory>

struct transform2D
{
    Vector2 position;
    float rotation;
    Vector2 scale;
    transform2D(Vector2 pos, float rtn, Vector2 scl);
    transform2D();
};

class Scene2D;

class Node2D : public std::enable_shared_from_this<Node2D>
{
    std::string name;
    std::unordered_map<std::string, std::shared_ptr<Node2D>> SubNodes;
    std::unordered_map<std::string, std::unique_ptr<Component2D>> Components;
    bool Activate = 1; 
    std::weak_ptr<Node2D> parent;
    Node2D(std::string _name);
    transform2D transform;

    public:
    
    ~Node2D();
    bool isActivate();
    void setActivate(bool _activate);
    void addComponent(std::unique_ptr<Component2D> _comp);
    void removeComponent(std::string _compName);
    void giveComponent(std::string _compName, Node2D* _node);
    Component2D* GetComponent(std::string _compName);
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
#pragma once
#include "raylib.h"
#include <vector>
#include "Component2D.h"
#include <string>
#include <unordered_set>
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


class Node2D : public std::enable_shared_from_this<Node2D>
{
    transform2D transform;
    std::unordered_set<std::shared_ptr<Node2D>> SubNodes;
    std::unordered_map<std::string, std::unique_ptr<Component2D>> Components;
    bool Activate = 1; 
    std::weak_ptr<Node2D> parent;
    Node2D(std::string _name):name(_name){};
    

    friend void setParentShip(std::shared_ptr<Node2D> prtNode, std::shared_ptr<Node2D> subNode);
    public:
    std::string name;
    static std::shared_ptr<Node2D> create(std::string _name);
    
    bool isActivate();
    void setActivate(bool _acti);
    void addComponent(std::unique_ptr<Component2D> _comp,std::string _compName);
    void removeComponent(std::string _compName);
    void giveComponent(std::string _compName, std::shared_ptr<Node2D> _node);
    void setParent(std::shared_ptr<Node2D> ptrNode);
    void delSubNode(std::shared_ptr<Node2D>& _node);
    
    void freeSubNode(std::shared_ptr<Node2D> _subnode);
    std::unordered_set<std::shared_ptr<Node2D>> GetSubNodes();

    void setPosition(Vector2 _pos);
    Vector2 getPosition();
    void setTransform(transform2D _trans);
    transform2D getTransform();

    virtual void Start();
    virtual void Update(float _delta);
    void SubNodesStart();
    void SubNodesUpdate(float _delta);
    void ComponentsStart();
    void ComponentsUpdate(float _delta);
};

void setParentShip(std::shared_ptr<Node2D> prtNode, std::shared_ptr<Node2D> subNode);
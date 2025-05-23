#pragma once
#include "raylib.h"
#include <string>

class Node2D;

class Component2D
{
    private:
    bool Activate = 1;
    Node2D* parent;
    public:

    std::string name;
    bool isActivate();
    void setActivate(bool _activate);
    Component2D(std::string _name, Node2D* _parent);
    Component2D(std::string _name, Node2D* _parent, bool _Activate);
    void setParent(Node2D* _parent);
    Node2D* getParent(void);
    virtual ~Component2D() = default;
    virtual void Start();
    virtual void Update(float _delta);

};

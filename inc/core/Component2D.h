#pragma once
#include "raylib.h"
#include <string>
#include <memory>


class Node2D;

class Component2D : public std::enable_shared_from_this<Component2D>
{
protected:
    bool Activate = 1;
    std::weak_ptr<Node2D> owner;


    Component2D(){};
    Component2D(bool _Activate):Activate(_Activate){}

public:

    static std::unique_ptr<Component2D> create();
    static std::unique_ptr<Component2D> create(bool _acti);
    bool isActivate();
    void setActivate(bool _acti);
    std::weak_ptr<Node2D> getOwner() const;
    void setOwner(std::weak_ptr<Node2D> _parent);
    virtual ~Component2D() = default;

    virtual void Start();
    virtual void Update(float _delta);

};

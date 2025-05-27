#include "Component2D.h"
#include "Node2D.h"

Component2D::Component2D(std::string _name, Node2D* _parent)
{
    name = _name;
    parent = _parent;
}

Component2D::Component2D(std::string _name, Node2D* _parent, bool _Activate)
{
    name = _name;
    parent = _parent;
    Activate = _Activate;
}


void Component2D::setParent(Node2D* _parent)
{
    parent = _parent;
}

Node2D* Component2D::getParent()
{
    return parent;
}

void Component2D::Start()
{

}

void Component2D::Update(float _delta)
{

}

bool Component2D::isActivate()
{
    return Activate;
}

void Component2D::setActivate(bool _activate)
{
    Activate = _activate;
}
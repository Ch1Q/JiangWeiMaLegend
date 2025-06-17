#include "Component2D.h"

void Component2D::setOwner(std::weak_ptr<Node2D> _owner)
{
    owner = _owner;
}

std::unique_ptr<Component2D> Component2D::create()
{
    return std::make_unique<Component2D>(Component2D());
}

std::unique_ptr<Component2D> Component2D::create(bool _acti)
{
    return std::make_unique<Component2D>(Component2D(_acti));
}

bool Component2D::isActivate()
{
    return Activate;
}

void Component2D::setActivate(bool _acti)
{
    Activate = _acti;
}

std::weak_ptr<Node2D> Component2D::getOwner() const
{
    return owner;
}

void Component2D::Start()
{
    
}
void Component2D::Update(float _delta)
{
    
}
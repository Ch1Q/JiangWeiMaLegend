#include "Component2D.h"

Component2D::Component2D(std::string _name)
{
    name = _name;
}

Component2D::Component2D(std::string _name, bool _Activate)
{
    name = _name;
    Activate = _Activate;
}

Component2D::~Component2D()
{
    
}

void Component2D::Start()
{

}

void Component2D::Update(float _deltatime)
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
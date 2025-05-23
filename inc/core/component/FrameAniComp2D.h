#pragma once
#include "Component2D.h"
class AnimationComponent2D : public Component2D
{
private:
    /* data */
public:
    AnimationComponent2D(std::string _name, Node2D* _parent) ;
    ~AnimationComponent2D();
};


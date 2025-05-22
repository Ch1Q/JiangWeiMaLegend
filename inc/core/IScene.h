#pragma once
#include <string>

class IScene2D
{
private:
    /* data */
public:
    std::string name;
    virtual ~IScene2D() = default;
};

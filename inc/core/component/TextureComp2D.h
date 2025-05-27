#pragma once
#include "raylib.h"
#include "Component2D.h"

class TextureComp2D : public Component2D
{

private:
    Texture2D texture;
    bool Visibility = 1;
public:
    TextureComp2D(std::string name, Node2D* _parent, std::string path);
    TextureComp2D(std::string name, Node2D* _parent, bool _vis);
    TextureComp2D(std::string name, Node2D* _parent, std::string path, bool _vis);
    TextureComp2D(const TextureComp2D&) = delete;
    TextureComp2D& operator=(const TextureComp2D&) = delete;
    ~TextureComp2D();
    void Start() override;
    void Update(float _delta) override;
    bool Load(std::string _path);
    void setVisibility(bool _vis);
    bool isVisible();
};

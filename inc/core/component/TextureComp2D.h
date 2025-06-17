#pragma once
#include "raylib.h"
#include "Component2D.h"
#include <iostream>
#include <functional>
#include "Node2D.h"
class TextureComp2D : public Component2D
{

private:
    Texture2D texture;
    bool Visibility = 1;

protected:
    TextureComp2D(std::string path);
    TextureComp2D(bool _vis);
    
    TextureComp2D(std::string path, bool _acti);
    TextureComp2D(bool _vis, bool _acti);
    TextureComp2D(std::string path, bool _vis, bool _acti);
public:

    TextureComp2D& operator=(const TextureComp2D&) = delete;
    ~TextureComp2D();

    static std::unique_ptr<TextureComp2D> create(std::string path);
    static std::unique_ptr<TextureComp2D> create(bool _vis);
    static std::unique_ptr<TextureComp2D> create(std::string path, bool _acti);
    static std::unique_ptr<TextureComp2D> create(bool _vis, bool _acti);
    static std::unique_ptr<TextureComp2D> create(std::string path, bool _vis, bool _acti);


    void Start() override;
    void Update(float _delta) override;
    bool Load(std::string _path);
    void setVisibility(bool _vis);
    bool isVisible() const;
};

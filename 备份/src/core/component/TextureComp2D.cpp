#include "TextureComp2D.h"
#include <iostream>
#include "Node2D.h"
TextureComp2D::TextureComp2D(std::string _name, Node2D* _parent, std::string path):Component2D(_name,_parent)
{
    texture = LoadTexture(path.c_str());
    if(!texture.id)std::cout<<name<<" failed to load "<<path<<"."<<std::endl;
}

TextureComp2D::TextureComp2D(std::string _name, Node2D* _parent, bool _vis):Component2D(_name,_parent)
{
    Visibility = _vis;
    Texture2D tex;
    tex.id = 0;
    texture = tex;
}

TextureComp2D::TextureComp2D(std::string _name, Node2D* _parent, std::string path, bool _vis):Component2D(_name,_parent)
{
    Visibility = _vis;
    texture = LoadTexture(path.c_str());
    if(!texture.id)std::cout<<name<<" failed to load "<<path<<"."<<std::endl;
}

TextureComp2D::~TextureComp2D()
{
    if(texture.id)UnloadTexture(texture);
}

void TextureComp2D::Start()
{

}

void TextureComp2D::Update(float _delta)
{
    if(this->isActivate()&& getParent())
    {
        transform2D trans = getParent()->transform;
        if(this->isVisible())
        {   
            DrawTexture(texture,trans.position.x,trans.position.y,WHITE);
        }
    }
}

bool TextureComp2D::Load(std::string _path)
{
    if(texture.id){std::cout<<name<<" is occupied "<<"."<<std::endl;return 0 ;}
    texture = LoadTexture(_path.c_str());
    if(!texture.id){std::cout<<name<<" failed to load "<<_path<<"."<<std::endl;return 0;}
    return 1;
}

void TextureComp2D::setVisibility(bool _vis)
{
    Visibility = _vis;
}

bool TextureComp2D::isVisible()
{
    return Visibility;
}
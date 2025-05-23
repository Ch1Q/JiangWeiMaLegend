#include "Scene2D.h"
#include <iostream>
Scene2D::Scene2D(std::string _name)
{
    name = _name;
}

Scene2D::Scene2D(std::string _name, bool _Activate)
{
    name = _name;
    isActivate = _Activate;
}

Scene2D::~Scene2D()
{
    for(auto n : Nodes) delete n;
}

void Scene2D::AddNode(Node2D* node)
{
    if(node == nullptr){std::cout<<"nullptr! node not found";return ;}
    for(auto n : Nodes)
    {
        if(n == node)
        {
            std::cout<<"Duplicate Node! "<<name<<" already has the node"<<node->name<<"."<<std::endl;
            return;
        }
    }
    Nodes.push_front(node);
}

void Scene2D::DelNode(Node2D* node)
{
    bool nodeIsIn = 0;
    if(node == nullptr){std::cout<<"nullptr! node not found";return ;}
    for(auto a : Nodes)if(a==node) nodeIsIn = 1;
    if(!nodeIsIn)
    {
        std::cout<<"DelError:"<<name<<"doesn't own the "<<node->name<<" node.";
        return;
    }
    delete node;
    Nodes.remove(node);
}

void Scene2D::GiveNode(Node2D* _node, Scene2D* _scene)
{
    bool nodeIsIn = 0;
    if(_node == nullptr){std::cout<<"nullptr! node not found";return ;}
    for(auto a : Nodes)if(a==_node) nodeIsIn = 1;
    if(!nodeIsIn)
    {
        std::cout<<"DelError:"<<name<<"doesn't own the "<<_node->name<<" node.";
        return;
    }
    _scene->Nodes.push_front(_node);
    Nodes.remove(_node);
}

std::forward_list<Node2D*> Scene2D::GetNodes()
{
    return Nodes;
}

void Scene2D::Start()
{
    for( auto& n : Nodes )if(n->isActivate())n->Start();
}

void Scene2D::Update(float _delta)
{
    for( auto& n : Nodes )if(n->isActivate())n->Update(_delta);
}

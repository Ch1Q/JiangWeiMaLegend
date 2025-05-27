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

void Scene2D::AddNode(Node2D* _node)
{
    if(_node == nullptr){std::cout<<"nullptr! "<<std::endl;return ;}
    for(auto n : Nodes)
    {
        if(n == _node)
        {
            std::cout<<"Duplicate Node! "<<name<<" already has the node"<<_node->name<<"."<<std::endl;
            return;
        }
    }
    Nodes.push_front(_node);
}

void Scene2D::DelNode(Node2D* _node)
{
    if(_node == nullptr){std::cout<<"nullptr! "<<std::endl;return ;}
    std::forward_list<Node2D*> toDel;
    for(auto n : Nodes)
    {
        if(n == _node)
        {
            toDel.push_front(n);
        }
    }
    if(toDel.empty()){std::cout<<name<<" doesn't have the node"<<std::endl; return;}
    for(auto n : toDel)
    {
        delete n;
        Nodes.remove(n);
    }
}

void Scene2D::DelNode(std::string _nodeName)
{
    std::forward_list<Node2D*> toDel;
    for(auto n : Nodes)
    {
        if(n->name == _nodeName)
        {
            toDel.push_front(n);
        }
    }
    if(toDel.empty()){std::cout<<name<<" doesn't have the node"<<_nodeName<<std::endl; return;}
    for(auto n : toDel)
    {
        delete n;
        Nodes.remove(n);
    }
}

void Scene2D::GiveNode(Node2D* _node, Scene2D* _scene)
{
    if(_node == nullptr){std::cout<<"nullptr! "<<std::endl;return ;}
    std::forward_list<Node2D*> toGive;
    for(auto n : Nodes)
    {
        if(n == _node)
        {
            toGive.push_front(n);
        }
    }
    if(toGive.empty()){std::cout<<name<<" doesn't have the node"<<std::endl; return;}
    for(auto n : toGive)
    {
        _scene->AddNode(n);
        Nodes.remove(n);
    }
}

void Scene2D::GiveNode(std::string _nodeName, Scene2D* _scene)
{
    std::forward_list<Node2D*> toGive;
    for(auto n : Nodes)
    {
        if(n->name == _nodeName)
        {
            toGive.push_front(n);
        }
    }
    if(toGive.empty()){std::cout<<name<<" doesn't have the node"<<std::endl; return;}
    for(auto n : toGive)
    {
        _scene->AddNode(n);
        Nodes.remove(n);
    }
}

Node2D* Scene2D::GetNode(std::string _nodeName)
{
    for(auto n : Nodes)
    {
        if(n->name == _nodeName)return n;
    }
    std::cout<<name<<" doesn't have the node "<<_nodeName<<"."<<std::endl;
    return nullptr;
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

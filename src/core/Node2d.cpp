#include "Node2D.h"
#include <iostream>
#include "Scene2D.h"

transform2D::transform2D(Vector2 pos , float rtn, Vector2 scl )
{
    position = pos;
    rotation = rtn;
    scale = scl;
}

transform2D::transform2D()
{
    position.x = 0; position.y = 0;
    rotation = 0;
    scale.x = 0; scale.y = 0;
}

Node2D::Node2D(std::string _name)
{
    name = _name;
}

Node2D::Node2D(std::string _name,bool _Activate)
{
    name = _name;
    Activate = _Activate;
}

Node2D::Node2D(std::string _name,transform2D _trans)
{
    name = _name;
    transform = _trans;
}

Node2D::~Node2D()
{
    for(auto c : Components)delete c;
    for(auto n : SubNodes)delete n;
}

bool Node2D::isActivate()
{
    return Activate;
}

void Node2D::setActivate(bool _activate)
{
    Activate = _activate;
}

void Node2D::AddComponent(Component2D* _comp)
{
    if(_comp == nullptr){std::cout<<"nullptr!";return;}
    for(auto c : Components)
    {
        if(c == _comp)
        {
            std::cout<<"Duplicate Component: "<< name<<" already has the component "<<_comp->name<<"."<<std::endl;
            return;
        }
    }
    Components.push_front(_comp);
}

void Node2D::DelComponent(Component2D* _comp)
{
    if(_comp == nullptr){std::cout<<"nullptr!";return;}
    bool compIsIn = 0;
    for(auto c : Components)if(c == _comp)compIsIn = 1;
    if(!compIsIn)
    {
        std::cout<<"Error:"<<name<<" dosen't has the component "<<_comp->name<<"."<<std::endl;
        return;
    }
    delete _comp;
    Components.remove(_comp);
}

void Node2D::DelComponent(std::string _comp)
{
    bool compIsIn = 0;
    for(auto c : Components)if(c->name == _comp)
    {
        compIsIn = 1;
        delete c;
        Components.remove(c);
    }
    if(!compIsIn)std::cout<<"there is no "<<_comp<<" component"<<std::endl;
}

void Node2D::GiveComponent(Component2D* _comp, Node2D* _node)
{
    if(_comp == nullptr){std::cout<<"nullptr!";return;}
    bool compIsIn = 0;
    for(auto c : Components)if(c == _comp)compIsIn = 1;
    if(!compIsIn)
    {
        std::cout<<"Error:"<<name<<" dosen't has the component "<<_comp->name<<"."<<std::endl;
        return;
    }
    _comp->setParent(_node);
    _node->AddComponent(_comp);
    Components.remove(_comp);
}

void Node2D::GiveComponent(std::string _comp, Node2D* _node)
{
    bool compIsIn = 0;
    for(auto c : Components)if(c->name == _comp)
    {
        compIsIn = 1;
        c->setParent(_node);
        _node->AddComponent(c);
        Components.remove(c);
    }
    if(!compIsIn)std::cout<<"there is no "<<_comp<<" component"<<std::endl;
}

void Node2D::AddSubNode(Node2D* _node)
{
    if(_node == nullptr){std::cout<<"nullptr!";return;}
    for(auto n : SubNodes)
    {
        if(n == _node)
        {
            std::cout<<"Duplicate Component: "<< name<<" already has the subNode "<<_node->name<<"."<<std::endl;
            return;
        }
    }
    SubNodes.push_front(_node);
}

void Node2D::DelSubNode(Node2D* _node)
{
    if(_node == nullptr){std::cout<<"nullptr!";return;}
    bool nodeIsIn = 0;
    for(auto n : SubNodes)if(n == _node)nodeIsIn = 1;
    if(!nodeIsIn)
    {
        std::cout<<"Error:"<<name<<" dosen't has the subNode "<<_node->name<<"."<<std::endl;
        return;
    }
    delete _node;
    SubNodes.remove(_node);
}

void Node2D::DelSubNode(std::string _node)
{
    bool compIsIn = 0;
    for(auto n : SubNodes)if(n->name == _node)
    {
        compIsIn = 1;
        delete n;
        SubNodes.remove(n);
    }
    if(!compIsIn)std::cout<<"there is no "<<_node<<" subNodes"<<std::endl;
}

void Node2D::GiveSubNode(Node2D* _subNode, Node2D* _toNode)
{
    if(_subNode == nullptr){std::cout<<"nullptr!";return;}
    bool subNodeIsIn = 0;
    for(auto n : SubNodes)if(n == _subNode)subNodeIsIn = 1;
    if(!subNodeIsIn)
    {
        std::cout<<"Error:"<<name<<" dosen't has the subNode "<<_subNode->name<<"."<<std::endl;
        return;
    }
    _subNode->parentNode = _toNode;
    _toNode->AddSubNode(_subNode);
    SubNodes.remove(_subNode);
}

void Node2D::GiveSubNode(std::string _node, Scene2D* _scene)
{
    bool subNodeIsIn = 0;
    for(auto n : SubNodes)if(n->name == _node)
    {
        subNodeIsIn = 1;
        _scene->AddNode(n);
        SubNodes.remove(n);
        n->parentNode = nullptr;
    }
    if(!subNodeIsIn)std::cout<<"there is no "<<_node<<" subNode"<<std::endl;
}

std::forward_list<Component2D*> Node2D::GetComponents()
{
    return Components;
}

std::forward_list<Node2D*> Node2D::GetSubNodes()
{
    return SubNodes;
}

void Node2D::Start()
{
    SubNodesStart();
    ComponentsStart();
}

void Node2D::Update(float _delta)
{
    SubNodesUpdate(_delta);
    ComponentsUpdate(_delta);
}

void Node2D::SubNodesStart()
{
    for(auto& n : SubNodes)
    {
        if(n->isActivate())n->Start();
    }
}

void Node2D::SubNodesUpdate(float _delta)
{
    for(auto& n : SubNodes)
    {
        if(n->isActivate())n->Update(_delta);
    }
}

void Node2D::ComponentsStart()
{
    for(auto& c : Components)
    {
        if(c->isActivate())c->Start();
    }
}

void Node2D::ComponentsUpdate(float _delta)
{
    for(auto& c : Components)
    {
        if(c->isActivate())c->Update(_delta);
    }
}

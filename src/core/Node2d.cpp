#include "Node2D.h"
#include "Component2D.h"
#include <iostream>

transform2D::transform2D(Vector2 pos, float rtn, Vector2 scl)
{
    position = pos;
    rotation = rtn;
    scale = scl;
}

transform2D::transform2D()
{
    position.x = 0;
    position.y = 0;
    rotation = 0;
    scale.x = 1;
    scale.y = 1;
}

std::shared_ptr<Node2D> Node2D::create(std::string _name)
{
    return std::shared_ptr<Node2D>(new Node2D(_name));
}

bool Node2D::isActivate()
{
    return Activate;
}

void Node2D::setActivate(bool _acti)
{
    Activate = _acti;
}

void Node2D::addComponent(std::unique_ptr<Component2D> _comp, std::string _name)
{
    if(!_comp)
    {
        std::cout<<"addComponent failed: "<<name<<" can't add nullptr "<<_name<<std::endl;
        return;
    }
    for(auto& n : Components)if(n.first == _name)
        {
            std::cout<<"addComponent failed: "<<name<<" already own the component named "<<_name<<std::endl;
            return;
        }
    _comp->setOwner(shared_from_this());
    Components[_name] = std::move(_comp);
}

void Node2D::removeComponent(std::string _compName)
{
    auto it = Components.find(_compName);
    if(it != Components.end())
    {
        it->second.reset();
        Components.erase(it);
        return;
    }
    std::cout << "removeComponent failed: "<< name << " doesn't own the component named " << _compName << std::endl;
    return;
}


void Node2D::giveComponent(std::string _compName, std::shared_ptr<Node2D> _node)
{
    if(_node == nullptr)
    {
        std::cout << "delSubnode failed: "<< name << " nullptr! " << std::endl;
    }
    auto it = Components.find(_compName);
    if(it != Components.end())
    {
        _node->Components[_compName] = std::move(it->second);
        it->second->setOwner(_node);
        Components.erase(it);
        return;
    }
    std::cout << "giveComponent failed: "<< name << " doesn't own the component named " << _compName << std::endl;
    return;
}

void Node2D::delSubNode(std::shared_ptr<Node2D>& _node)
{
    if(_node == nullptr)
    {
        std::cout << "delSubnode failed: "<< name << " nullptr! " << std::endl;
    }
    auto it = SubNodes.find(_node);
    if(it != SubNodes.end())
    {
        _node.reset();
        SubNodes.erase(it);
        return;
    }
    std::cout << "delSubnode failed: "<< name << " doesn't own the subnode " << std::endl;
    return;
}

void Node2D::setParent(std::shared_ptr<Node2D> prtNode)
{
    parent = prtNode;

}

void setParentShip(std::shared_ptr<Node2D> prtNode, std::shared_ptr<Node2D> subNode)
{
    // 防止自循环
    if(prtNode == subNode) {
        std::cout << "setParentShip错误: 不能设置自己为父节点" << std::endl;
        return;
    }
    
    // 防止祖先循环
    for(auto node = prtNode; node; node = node->parent.lock()) {
        if(node == subNode) {
            std::cout << "setParentShip错误: 循环父子关系 (" 
                      << subNode->name << " 已是 " << prtNode->name << " 的祖先)" << std::endl;
            return;
        }
    }

    if((prtNode == nullptr) || (subNode == nullptr))
    {
        std::cout << "setParent failed: "<< " nullptr! " << std::endl;
        return;
    }
    if(!(subNode->parent.expired()))
    {
        std::cout<< "setParentShip failed: "<< subNode->name << "already has an owner" <<std::endl;
        return;
    }
    subNode->setParent(prtNode);
    prtNode->SubNodes.insert(subNode);
}


void Node2D::freeSubNode(std::shared_ptr<Node2D> _subnode)
{
    if(_subnode == nullptr)
    {
        std::cout<<"freeSubNode failed: "<<name<<" nullptr!"<<std::endl;
        return ;
    }
    auto it = SubNodes.find(_subnode);
    if(it != SubNodes.end())
    {
        _subnode->setParent(nullptr);
        SubNodes.erase(it);
        return ;
    }
    std::cout<<"freeSubNode failed: "<<name<<" dosen't have the subnode"<<std::endl;
}

std::unordered_set<std::shared_ptr<Node2D>> Node2D::GetSubNodes()
{
    return SubNodes;
}

void Node2D::setPosition(Vector2 _pos)
{
    transform.position = _pos;
}

Vector2 Node2D::getPosition()
{
    return transform.position;
}

void Node2D::setTransform(transform2D _trans)
{
    transform = _trans;
}

transform2D Node2D::getTransform()
{
    return transform;
}

void Node2D::SubNodesStart()
{
    for(auto& n : SubNodes)
{
        if(n->isActivate())n->Start();
    }
}

void Node2D::ComponentsStart()
{
    for(auto &c : Components)
    {
        if(c.second->isActivate())c.second->Start();
    }
}

void Node2D::SubNodesUpdate(float _delta)
{
    for(auto &n : SubNodes)
    {
        if(n->isActivate())n->Update(_delta);
    }
}
void Node2D::ComponentsUpdate(float _delta)
{
     for(auto &c : Components)
    {
        if(c.second->isActivate())c.second->Update(_delta);
    }
}
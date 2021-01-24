#include "GameObject.h"

GameObject::GameObject(std::string name) :
	m_name(name)
{

}

GameObject::~GameObject()
{

}

std::string GameObject::getName()
{
    return m_name;
}

void GameObject::setName(std::string name)
{
	m_name = name;
}

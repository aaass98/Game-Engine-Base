#include "GameObject.h"
#include <iostream>
Component::Component(GameObject& gameObject)
{
	_parent = &gameObject;
	gameObject.add(this);
}

Component::~Component()
{
	cout << "Destroying " << "component in " << _parent->getName() << "gameobject.\n";
	_parent->_componentList.remove(this);
}

string Component::getParentName() 
{
	return _parent->getName();
}
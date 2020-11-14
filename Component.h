#ifndef __Component_h
#define __Component_h
#include <iostream>
using namespace std;
class GameObject;

class Component abstract
{
public:
	Component(GameObject&);
	~Component();
	virtual void print() const abstract;//override with print for each class TODO
	virtual string getType() const abstract;//override with return string
	string getParentName();

protected:
	GameObject* _parent;
	Component* _next;
	Component* _previous;

	friend class ComponentList;

};
#endif
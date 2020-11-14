#ifndef __ComponentList_h
#define __ComponentList_h

#include "Component.h"
/*ADD:
*remove all components except transform
*get component pointer given component type
*iterate
*/

class ComponentList{
public:
	ComponentList()
	{
		_head = _tail = nullptr;
		_count = 0;
	}

	~ComponentList()
	{
		while (_head != nullptr)
		{
			delete _head;
		}
	}

	Component* getComponentPtr(string type) {
		Component* tempComponent = _head;
		while (tempComponent != nullptr) {
			if (type.compare(tempComponent->getType())==0) {
				printf("Component found, returning pointer\n");
				return tempComponent;
			}
			tempComponent = tempComponent->_next;
		}
		printf("Component not found\n");
		return nullptr;
	}

	void add(Component* component)
	{
		//checking for repeated components
		Component* tempComponent = _head;
		while (tempComponent != nullptr ) {
			if (tempComponent->getType() == component->getType()) {
				printf("ERROR! This object already has a component of this type.\n");
				return;
			}
			tempComponent = tempComponent->_next;
		}
		//adding component to list
		if (_head == nullptr)
			_head = component;
		else
			_tail->_next = component;
		component->_previous = _tail;
		component->_next = nullptr;
		_tail = component;
		_count++;
		printf("Component sucessfully added\n");
	}

	void remove(Component* component)
	{
		if (component != nullptr) {
			//if component is head, then it's a transform
			if (component == _head) {
				printf("Can't remove a game object's transform.\n");
			}
			else //also, component->_previous will never be nullptr, since it only happens on head/transform
			{
				if (component->_next != nullptr)
					component->_next->_previous = component->_previous;
				if (component == _tail)
					_tail = component->_previous;
				delete component;
				_count--;
			}
		}
		printf("Component sucessfully removed.\n");
	}

	void print() {
		Component* tempComponent = _head;
		while (tempComponent != nullptr) {
			tempComponent->print();
			tempComponent = tempComponent->_next;
		}
	}

private:
	Component* _head;
	Component* _tail;
	int _count;

	friend class GameObject;
};

#endif
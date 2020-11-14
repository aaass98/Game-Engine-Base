#ifndef __GameObjectList_h
#define __GameObjectList_h

#include "GameObject.h"

/*ADD:
* clearList (without deleting)
* iterate
*/
class GameObjectList {
public:
	GameObjectList()
	{
		_head = _tail = nullptr;
		_count = 0;
	}

	~GameObjectList()
	{
		while (_head != nullptr)
		{
			delete _head;
		}
	}

	void add(GameObject* gameObject)
	{
		if (_head == nullptr)
			_head = gameObject;
		else
			_tail->_next = gameObject;
		gameObject->_previous = _tail;
		gameObject->_next = nullptr;
		_tail = gameObject;
		_count++;
	}

	void remove(GameObject* gameObject)
	{
		if (gameObject != nullptr) {
			if (gameObject->_previous != nullptr)
				gameObject->_previous->_next = gameObject->_next;
			if (gameObject->_next != nullptr)
				gameObject->_next->_previous = gameObject->_previous;
			if (gameObject == _head)
				_head = gameObject->_next;
			if (gameObject == _tail)
				_tail = gameObject->_previous;
			delete gameObject;
			_count--;
		}
	}

	GameObject* getGameObjectPtr(string name) {
		GameObject* tempObj = _head;
		while (tempObj != nullptr) {
			if (name.compare(tempObj->getName())==0) {
				printf("Game Object found, returning pointer\n");
				return tempObj;
			}
			tempObj = tempObj->_next;
		}
		printf("Game object not found\n");
		return nullptr;
	}

	void print() {
		GameObject* tempGameObj = _head;
		while (tempGameObj != nullptr) {
			tempGameObj->print();
			tempGameObj = tempGameObj->_next;
		}
	}

private:
	GameObject* _head;
	GameObject* _tail;
	int _count;

	friend class GameObject;
	friend class Scene;
};

#endif
#ifndef __SceneList_h
#define __SceneList_h



/*ADD:
* iterate
*/
class SceneList {
public:
	SceneList()
	{
		_head = _tail = nullptr;
		_count = 0;
	}

	~SceneList()
	{
		while (_head != nullptr)
		{
			delete _head;
		}
	}
	
	Scene* getScenePtr(string name)
	{
		Scene* tempScene = _head;
		while (tempScene != nullptr) {
			if (name.compare(tempScene->getName())==0) {
				printf("Scene found, returning pointer\n");
				return tempScene;
			}
			tempScene = tempScene->_next;
		}
		printf("Scene not found\n");
		return nullptr;
	}

	void add(Scene* scene)
	{
		if (_head == nullptr)
			_head = scene;
		else
			_tail->_next = scene;
		scene->_previous = _tail;
		scene->_next = nullptr;
		_tail = scene;
		_count++;
	}

	void remove(Scene* scene)
	{
		if (scene != nullptr) {
			if (scene->_previous != nullptr)
				scene->_previous->_next = scene->_next;
			if (scene->_next != nullptr)
				scene->_next->_previous = scene->_previous;
			if (scene == _head)
				_head = scene->_next;
			if (scene == _tail)
				_tail = scene->_previous;
			_count--;
		}
	}

	void print() {
		Scene* tempScene = _head;
		while (tempScene != nullptr) {
			tempScene->print();
			tempScene = tempScene->_next;
		}
	}

private:
	Scene* _head;
	Scene* _tail;
	int _count;
	friend class Game;
};

#endif
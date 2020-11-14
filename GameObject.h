#ifndef __GameObject_h
#define __GameObject_h

#include "ComponentList.h"

/*ADD:
* print ->first finish iterate on lists
* Destructor
*/
class Scene;
class GameObjectList;
class GameObject{
public:
	GameObject(string, Scene&);
	GameObject(string, GameObject&);
	~GameObject();
	
	inline string getName(){
		return _name;
	}
	inline void setName(string newName) {
		_name = newName;
	}

	Component* getComponentPtr(string);
	GameObject* getGameObjectPtr(string);

	void print();

	void removeComponent(string);
	void removeGameObject(string);
	void removeAllComponents();
	void removeAllGameObjects();
	void add(GameObject*);
	void add(Component*);

private:
	string _name;
	ComponentList _componentList;
	GameObjectList* _gameObjectList;
	
	GameObject* _parentGameObject = nullptr;
	Scene* _parentScene = nullptr;
	GameObject* _next;
	GameObject* _previous;

	friend class Component;
	friend class GameObjectList;
	friend class Transform;
	friend class Mesh;
	friend class Light;
	friend class Camera;
};
#endif
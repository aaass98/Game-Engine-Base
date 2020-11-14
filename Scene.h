#ifndef __Scene_h
#define __Scene_h
#include "GameObject.h"
#include "GameObjectList.h"
/*ADD:
* iterate obj list
* print scene -> printf(name) and print(objectlist)
*/
class Game;
class GameObjectList;
class Scene
{
public:
	Scene(Game&, string);//TO DO make a cube, a light and a camera
	~Scene();//TO DO
	string getName() 
	{
		return _name;
	}
	void setName(string name) 
	{
		_name = name;
	}

	void add(GameObject*);
	void remove(string);
	GameObject* getGameObjectPtr(string);
	void removeAllGameObjects();
	void print();
private:
	Game* _parent;
	string _name;
	GameObjectList _gameObjectList;
	Scene* _next;
	Scene* _previous;

	friend class SceneList;
	friend class GameObject;
};
#endif

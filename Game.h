#ifndef __Game_h
#define __Game_h

#include "Scene.h"
#include "SceneList.h"
/*ADD:
*iterate
*print
*/

class Game{
public:
	Game(string);
	~Game();
	string getName() 
	{
		return _name;
	}
	void setName(string name)
	{
		cout << "Changing name from " << _name << " to " << name << ". \n";
		_name = name;
	}
	void add(Scene*);
	void remove(string);
	void removeAllScenes();
    Scene* getScenePtr(string);
	void print();

private:
	string _name;
	SceneList _sceneList;

	friend class Scene;
};

#endif

#include "Light.h"
#include "Mesh.h"
#include "Camera.h"
#include "Scene.h"
#include "GameObjectList.h"
#include "GameObject.h"
#include "Game.h"

Scene::Scene(Game& game, string name) 
{	_name=name;
	_parent = &game;
	game.add(this);
	//add a Cube
	GameObject cube = GameObject("Cube", *this);
	new Mesh(cube);
	//add a light
	GameObject light = GameObject("Light", *this);
	new Light(light);
	//add a camera
	GameObject camera = GameObject("Main Camera", *this);
	new Camera(camera);
	cout << name << " scene created sucessfully.\n";
}

Scene::~Scene() {
	cout << "Destroying " << "scene in '" << _parent->getName() << "' game\n";
	_parent->_sceneList.remove(this);
}

void Scene::add(GameObject* gameObject)
{
	_gameObjectList.add(gameObject);
	cout << gameObject->getName() << "added to scene.\n";
}

void Scene::remove(string name)
{
	_gameObjectList.remove(getGameObjectPtr(name));
	cout << name << " game object removed from scene.\n";
}

GameObject* Scene::getGameObjectPtr(string name) 
{
	return _gameObjectList.getGameObjectPtr(name);
}

void Scene::removeAllGameObjects()
{
	while (_gameObjectList._head != nullptr) {
		_gameObjectList.remove(_gameObjectList._tail);
	}
	cout << "All game objects removed from scene.\n";
}

void Scene::print()//printf 
{
	cout << "Scene Name: " << _name << endl << "Game Objects\n";
	_gameObjectList.print();
}
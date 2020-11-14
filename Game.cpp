#include "Game.h"

Game::Game(string name) {
	cout << "Creating \'" << name << "\' game.\n";
	_name = name;
	new Scene(*this, "Main Scene");
	cout<<"Game created sucessfully.\n";
}

Game::~Game() 
{
	cout<<this->getName()<<" game deleted";
	delete this;
}

void Game::add(Scene* scene) 
{
	printf("adding a scene\n");
	_sceneList.add(scene);
	cout << scene->getName() << " sucessfully added to \'" << _name << "\' game\n";
}

Scene* Game::getScenePtr(string name)
{
	printf("getting scene\n");
	return _sceneList.getScenePtr(name);
}

void Game::remove(string name) 
{
	printf("removing scene\n");
	_sceneList.remove(getScenePtr(name));
}

void Game::removeAllScenes() 
{
	while(_sceneList._head != nullptr) {
		printf("removing all scenes\n");
		_sceneList.remove(_sceneList._tail);
	}
}

void Game::print()
{
	cout << "Game Name: " << _name << endl << "Scenes\n";
	_sceneList.print();
}

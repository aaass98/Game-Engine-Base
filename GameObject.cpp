#include "Transform.h"
#include "Light.h"
#include "Mesh.h"
#include "Camera.h"
#include "Scene.h"
#include "GameObjectList.h"

GameObject::GameObject(string name, Scene& scene)
{
	cout << "creating '" << name << "' game object.\n";
	_parentScene = &scene;
	_name = name;
	scene._gameObjectList.add(this);
	new Transform(*this);
	cout<<name<<" game object sucessfully created.\n";
}
GameObject::GameObject(string name, GameObject& gameObject)
{	
	cout << "creating '" << name << "' game object.\n";
	_parentGameObject = &gameObject;
	_name = name;
	gameObject._gameObjectList->add(this);
	new Transform(*this); 
	cout<<name<<" game object sucessfully created.\n";
}
void GameObject::add(GameObject* newGameObject) 
{
	cout << "Adding '" << newGameObject->getName() << "' game object as '" << this->getName() << "' game object's children.\n";
	_gameObjectList->add(newGameObject);
	cout<<newGameObject->getName()<<" game object added as "<<this->getName()<<"game object's children.\n";
}
void GameObject::add(Component* newComponent) 
{
	cout << "Adding a new component to '"<<this->getName()<<"' game object.\n";
	_componentList.add(newComponent);
	cout << "Component added to " << this->getName() << " game object.\n";
}
Component* GameObject::getComponentPtr(string name) 
{
	printf("getting a component\n");
	return _componentList.getComponentPtr(name);
}
GameObject* GameObject::getGameObjectPtr(string name) 
{
	printf("getting a gameobject\n");
	return _gameObjectList->getGameObjectPtr(name);
}
void GameObject::removeComponent(string name) 
{
	printf("removing component\n");
	_componentList.remove(getComponentPtr(name));
}
void GameObject::removeGameObject(string name) 
{
	printf("removing gameobject\n");
	_gameObjectList->remove(getGameObjectPtr(name));
}
void GameObject::removeAllComponents() 
{
	printf("removing all components\n");
	while (_componentList._tail != _componentList._head) {
		_componentList.remove(_componentList._tail);
	}
}
void GameObject::removeAllGameObjects() 
{
	printf("removing all gameobjects\n");
	while (_gameObjectList->_head != nullptr) {
		_gameObjectList->remove(_gameObjectList->_tail);
	}
}
void GameObject::print() 
{
	cout << "Game Object Name: " << _name;
	if (_parentGameObject == nullptr) {
		printf("(Scene root)\n");
	}
	else {
		cout<<"(child of " << _parentGameObject->getName() << ")\n";
	}
	cout<< "Components contained:\n";
	_componentList.print();
	printf("Game Objects contained:\n");
	_gameObjectList->print();
}
GameObject::~GameObject()
{
	if (_parentGameObject != nullptr) {
		cout << "Destroying " << getName() << " object in " << _parentGameObject->getName() << " game object\n";
		_parentGameObject->_gameObjectList->remove(this);
	}
	else {
		cout << "Destroying " << getName() << " object in " << _parentScene->getName() << " scene\n";
		_parentScene->_gameObjectList.remove(this);
	}
}
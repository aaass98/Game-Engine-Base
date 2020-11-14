#include "Game.h"
#include "Mesh.h"
#include "Transform.h"
#include "Light.h"
#include "Camera.h"

int main() 
{
	printf("***************Section A1***************\n\n");
	printf("***Creating game***\n");
	Game newGame = Game("Test Game");
	printf("\n***Creating new scene***\n");
	Scene(newGame, "Scene 1");
	printf("\n***Removing main scene***\n");
	newGame.remove("Main Scene");
	printf("\n***Removing all scenes***\n");
	newGame.removeAllScenes();
	printf("\n***Creating a new scene and printing pointer***\n");
	Scene testScene1 = Scene(newGame, "Test Scene 1");
	printf("Scene stored at %p adress", newGame.getScenePtr("Test Scene 1"));
	printf("\n***Creating new scene for test purposes***\n");
	Scene testScene2 = Scene(newGame, "Test Scene 0");
	printf("\n***Printing game***\n");
	newGame.print();

	printf("\n***************Section A2***************\n\n");
	cout << "***Printing scene name before changing it: " << testScene2.getName()<<"***\n";
	testScene2.setName("Test Scene 2");
	cout << "\n***Printing scene name after changing: " << testScene2.getName()<<"***\n";
	printf("\n***Adding new game object to second scene***\n");
	GameObject("Test Object", testScene2);
	printf("\n***Removing Cube from first scene***\n");
	testScene1.remove("Cube");
	printf("\n***Removing all game objects from second scene***\n");
	testScene2.removeAllGameObjects();
	printf("\n***Getting pointer to Main Camera on first scene***\n");
	GameObject* camObj = testScene1.getGameObjectPtr("Main Camera");
	printf("Main Camera stored at %p adress.", camObj);
	printf("\n***Printing first scene***\n");
	testScene1.print();

	printf("\n***************Section A3***************\n\n");
	cout << "***Printing game object name before changing it: " << camObj->getName() << "***\n";
	camObj->setName("Camera");
	cout << "\n***Printing game object name after changing: " << camObj->getName() << "***\n";
	printf("\n***Adding new game objects to Camera***\n");
	GameObject("Test Object 1", *camObj);
	GameObject("Test Object 2", *camObj);
	GameObject("Test Object 3", *camObj);
	printf("\n***Removing test game object from Camera***\n");
	camObj->removeGameObject("Test Object 1");
	printf("\n***Test Object 2 stored at adress %p ***\n", camObj->getGameObjectPtr("Test Object 2"));
	printf("\n***Removing all game objects from Camera***\n");
	camObj->removeAllGameObjects();
	printf("\n***Adding Mesh Component to camera***\n");
	Mesh(*camObj);
	printf("\n***Removing Mesh from camera***\n");
	camObj->removeComponent("Mesh");
	printf("\n***Removing all components from camera***\n");
	camObj->removeAllComponents();
	Component* testComp = camObj->getComponentPtr("Transform");
	printf("\n***Transform component stored at adress %p ***\n", testComp);
	printf("\n***Printing Camera game object***\n");
	camObj->print();

	printf("\n***************Section A4***************\n\n");
	cout << "\n***Test Component = " << testComp->getType() << "***\n";
	printf("\n***Printing test component***\n");
	testComp->print();
}
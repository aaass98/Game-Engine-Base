#include "Mesh.h"

Mesh::Mesh(GameObject& gameObject) :
	Component(gameObject)
{
	printf("Mesh sucessfully created\n");
}

void Mesh::print() const 
{
	cout << "Light component in " << getParentName() << " game object.\n";
}

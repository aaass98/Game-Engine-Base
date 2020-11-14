#include "Light.h"

Light::Light(GameObject& gameObject) :
	Component(gameObject)
{
	printf("Light sucessfully created\n");
}

void Light::print() const 
{
	cout << "Light component in " << getParentName() << " game object.\n";
}

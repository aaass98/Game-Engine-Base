#include "Transform.h"

Transform::Transform(GameObject& gameObject) :
	Component(gameObject)
{
	printf("Transform sucessfully created\n");
}

void Transform::print() const
{
	cout << "Light component in " << getParentName() << " game object.\n";
}

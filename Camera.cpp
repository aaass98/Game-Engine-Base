#include "Camera.h"

Camera::Camera(GameObject& gameObject) :
	Component(gameObject)
{
	printf("Camera sucessfully created\n");
}

void Camera::print() const 
{
	cout << "Light component in " << getParentName() << " game object.\n";
}

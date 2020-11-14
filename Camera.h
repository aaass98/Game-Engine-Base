#ifndef __Camera_h
#define __Camera_h

#include "Component.h"
class GameObject;
class Camera : public Component
{
public:
	Camera(GameObject&);

	void print() const override;

	string getType() const override
	{
		return _type;
	}

	/*string getParentName() {
		return this->_parent->getName();
	}*/
private:
	string _type = "Camera";
};
#endif

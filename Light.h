#ifndef __Light_h
#define __Light_h

#include "Component.h"
class GameObject;
class Light : public Component
{
public:
	Light(GameObject&);

	void print() const override;

	string getType() const override
	{
		return _type;
	}

	/*string getParentName() {
		return this->_parent->getName();
	}*/
private:
	string _type = "Light";
};
#endif
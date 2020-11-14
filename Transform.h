#ifndef __Transform_h
#define __Transform_h

#include "Component.h"
class GameObject;
class Transform : public Component
{
public:
	Transform(GameObject&);

	void print() const override;

	string getType() const override
	{
		return _type;
	}

private:
	string _type = "Transform";
};
#endif
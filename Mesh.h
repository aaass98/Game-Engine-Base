#ifndef __Mesh_h
#define __Mesh_h

#include "Component.h"
class GameObject;
class Mesh : public Component
{
public:
	Mesh(GameObject&);

	void print() const override;

	string getType() const override
	{
		return _type;
	}


private:
	string _type = "Mesh";
};
#endif
#pragma once
#ifndef DEF_CLASS
#define DEF_CLASS


#include "GameObject.h"

class Class : public GameObject
{
public: 
	enum class UnitClass {
		WARRIOR,
		RANGER,
		WIZARD
	};
	UnitClass* getClass();
	Class(UnitClass classType = UnitClass::WARRIOR);

private:
	UnitClass m_classType;

};
#endif // !DEF_CLASS




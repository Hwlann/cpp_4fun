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

};
#endif // !DEF_CLASS




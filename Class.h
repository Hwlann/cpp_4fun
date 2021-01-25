#pragma once
#ifndef DEF_CLASS
#define DEF_CLASS


#include "GameObject.h"

enum class UnitClass {
	WARRIOR,
	RANGER,
	WIZARD
};

class Class : public GameObject
{
};
#endif // !DEF_CLASS




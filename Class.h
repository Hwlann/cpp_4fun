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
		UnitClass getClass();
		Class();

	protected:
		UnitClass m_classType = UnitClass::WARRIOR;

};
#endif // !DEF_CLASS




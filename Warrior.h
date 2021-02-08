#pragma once
#ifndef DEF_WARRIOR
#define DEF_WARRIOR
#include "Class.h"
#include "AiCharacter.h"

class Warrior : public Class, public AiCharacter
{
	public:
		Warrior();
		virtual ~Warrior();

	private:
};

#endif // !DEF_WARRIOR



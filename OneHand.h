#pragma once
#include "Weapon.h"
class OneHand : public virtual Weapon
{
	protected :
		Skill *m_offHandSkill = nullptr;
};


#pragma once
#include "Weapon.h"
class OneHand : public virtual Weapon
{
	public:
		OneHand();
		virtual ~OneHand();
		Skill* getOffHandSkill();

	protected :
		Skill *m_offHandSkill = nullptr;
};


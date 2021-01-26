#pragma once
#include "Weapon.h"
class OneHand : public virtual Weapon
{
	public:
		OneHand();
		virtual ~OneHand();
		Skill* getOffHandSkill();

		float getoffHandsDamageMultiplicator();

	protected :
		Skill *m_offHandSkill = nullptr;
		float m_offHandsDamageMultiplicator = 0.75;
};


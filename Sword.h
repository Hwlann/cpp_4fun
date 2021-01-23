#pragma once
#include "OneHand.h"
#include "TwoHands.h"

class Sword : public OneHand, public TwoHands
{
	public:
		Sword(Skill *mainSkill, Skill *offHandSkill);
		Sword(Skill* mainSkill, Skill* secondSkill);

	private:
		bool m_isTwoHanded = false;
};


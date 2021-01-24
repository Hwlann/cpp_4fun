#pragma once
#include "OneHand.h"
#include "TwoHands.h"

class Sword : public OneHand, public TwoHands
{
	public:
		Sword(bool isTwoHanded = false);
		virtual ~Sword();
		std::vector<Skill*> getSkills();

	private:
		int m_baseRange = 1;
		int m_baseDamage = 50;

		bool m_isTwoHanded = false;
		std::vector<Skill*> m_skills;
};


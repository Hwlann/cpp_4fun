#pragma once
#ifndef DEF_SKILL
#define DEF_SKILL
#include "GameObject.h"
#include "Effect.h"

class Skill : public GameObject
{
	public :

		Skill(int damage = 0 , int range = 0);
		virtual ~Skill();

		void addEffect(Effect::EffectCategory, Effect* effect);

		// GETTER
		int getDamage();
		int getRange();
		int getManaCost();

	private:
		int m_damage = 0;
		int m_range = 0;
		int m_manaCost = 0;

		Effect *m_primaryEffect = nullptr;
		Effect *m_secondaryEffet = nullptr;
};


#endif // !DEF_SKILL



#pragma once
#ifndef DEF_SKILL
#define DEF_SKILL
#include "GameObject.h"
#include "Effect.h"

class Skill : public GameObject
{
	public :
		Skill(int damage = 0, int aoe = 0, int range = 0);
		virtual ~Skill();

		void addEffect(Effect::EffectCategory, Effect* effect);

		// GETTER
		Effect* getPrimaryEffect();
		Effect* getSecondaryEffect();
		Effect::SkillType* getSkillType();

		int getDamage();
		int getRange();
		int getManaCost();

		void increaseDamage(float coef);

	private:
		int m_damage = 0; // > 0 = dmg ; < 0 = heal
		int m_range = 0;
		int m_manaCost = 0;
		int m_areaOfEffect = 0;

		Effect::SkillType* m_skillType = nullptr;
		Effect *m_primaryEffect = nullptr;
		Effect *m_secondaryEffect = nullptr;
};


#endif // !DEF_SKILL



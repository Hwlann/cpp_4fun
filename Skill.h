#pragma once
#ifndef DEF_SKILL
#define DEF_SKILL
#include "GameObject.h"
#include "Effect.h"
#include "Pattern.h"

class Skill : public GameObject
{
	public :
		Skill(int damage = 0, Pattern *castingPattern = nullptr, Pattern *aoePattern = nullptr,  bool applyOnAllies = false);
		virtual ~Skill();

		void addEffect(Effect::EffectCategory, Effect* effect);

		// GETTER
		bool getApplyOnAllies();

		Effect* getPrimaryEffect();
		Effect* getSecondaryEffect();
		Effect::SkillType* getSkillType();

		Pattern* getCastingPattern();
		Pattern* getAoePattern();

		int getDamage();
		int getRange();
		int getManaCost();

		void increaseDamage(float coef);

	private:
		int m_damage = 0; // > 0 = dmg ; < 0 = heal
		int m_range = 0;
		int m_manaCost = 0;
		int m_areaOfEffect = 0;
		bool m_applyOnAllies = false;

		Pattern* m_castingPattern = nullptr;
		Pattern* m_aoePattern = nullptr;

		Effect::SkillType* m_skillType = nullptr;
		Effect *m_primaryEffect = nullptr;
		Effect *m_secondaryEffect = nullptr;
};


#endif // !DEF_SKILL



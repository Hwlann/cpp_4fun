#pragma once
#ifndef DEF_EFFECT
#define DEF_EFFECT
#include "GameObject.h"
class Effect : public GameObject
{
	public:
		enum class EffectType {
			BUFF,
			DEBUFF
		};

		enum class EffectTarget {
			HEALTH,
			MANA,
			ARMOR,
			MAGICAL_RESISTANCE,
			MOVEMENT,
			DAMAGE
		};

		enum class EffectCategory {
			PRIMARY,
			SECONDARY
		};

		enum class SkillType {
			STRENGTH,
			INTELLIGENCE,
			DEXTERITY
		};

		Effect(EffectType effectType = EffectType::BUFF, EffectTarget effectTarget = EffectTarget::HEALTH, SkillType bonusDamageStat = SkillType::STRENGTH,  int amount = 0, int turns = 0, bool applyEachTurn = false);
		virtual ~Effect();

		// GETTERS
		int getAmount();
		int getNbTurns();
		bool getApplyEachTurn();
		EffectType* getEffectType();
		EffectTarget* getEffectTarget();
	
	private:
		int m_amount = 0;
		int m_turns = 0;
		bool m_applyEachTurn = false;

		SkillType m_bonusDamageStat;
		EffectType m_effectType;
		EffectTarget m_effectTarget;
};
#endif // !DEF_EFFECT


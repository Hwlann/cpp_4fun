#pragma once
#ifndef DEF_EFFECT
#define DEF_EFFECT
#include "GameObject.h"
#include "Curve.h"

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

		enum class EffectModifier {
			FLAT,
			PERCENT
		};

		enum class SkillType {
			STRENGTH,
			INTELLIGENCE,
			DEXTERITY
		};

		Effect(EffectType effectType = EffectType::BUFF, EffectTarget effectTarget = EffectTarget::HEALTH, EffectModifier effectModifier = EffectModifier::FLAT,  SkillType bonusDamageStat = SkillType::STRENGTH,  int amount = 0, int turns = 0, bool applyEachTurn = false);
		virtual ~Effect();

		// GETTERS
		int getAmount();
		int getNbTurns();
		bool getApplyEachTurn();
		EffectType* getEffectType();
		EffectTarget* getEffectTarget();
		EffectModifier* getEffectModifier();

		// METHODS
		void modifySkillAttributeBySkillType(int attribut);
	
	private:
		int m_amount = 0;
		int m_turns = 0;
		bool m_applyEachTurn = false;

		Curve* m_damageCurve= nullptr;

		SkillType m_bonusDamageStat;
		EffectType m_effectType;
		EffectTarget m_effectTarget;
		EffectModifier m_effectModifier;
};
#endif // !DEF_EFFECT



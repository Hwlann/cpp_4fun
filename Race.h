#pragma once
#ifndef DEF_RACE
#define DEF_RACE
#include "GameObject.h"
#include "Skill.h"

class Race : public GameObject
{
	public:
		enum class CharacterRace {
			ORK,
			HUMAN,
			ELF
		};

		Race();
		virtual ~Race();

		Skill* getPassiveSkill();
		std::pair<Effect::EffectTarget, float>* getRaceStatModifier();
		CharacterRace* getRaceType();


	protected:
		Skill* m_passiveSkill = nullptr;
		std::pair<Effect::EffectTarget, float> m_statModifier = std::pair<Effect::EffectTarget, float>(Effect::EffectTarget::HEALTH, 1.8f);
		CharacterRace m_raceType;


};
#endif // !DEF_RACE





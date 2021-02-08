#pragma once
#ifndef DEF_RACE
#define DEF_RACE
#include "GameObject.h"
#include "Skill.h"

class Race : public GameObject
{
	public:
		enum class UnitRace {
			ORK,
			HUMAN,
			ELF
		};

		Race(UnitRace type = UnitRace::ORK);
		virtual ~Race();

		Skill* getPassiveSkill();
		std::pair<Effect::EffectTarget, float>* getRaceStatModifier();
		UnitRace* getRaceType();


	protected:
		Skill* m_passiveSkill = nullptr;
		std::pair<Effect::EffectTarget, float> m_statModifier = std::pair<Effect::EffectTarget, float>(Effect::EffectTarget::HEALTH, 1.8f);
		UnitRace m_raceType;


};
#endif // !DEF_RACE





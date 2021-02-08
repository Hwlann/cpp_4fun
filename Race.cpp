#include "Race.h"

Race::Race(UnitRace type) :
	m_raceType(type)
{
}

Race::~Race()
{
}

Skill* Race::getPassiveSkill()
{
	return m_passiveSkill;
}

std::pair<Effect::EffectTarget, float>* Race::getRaceStatModifier()
{
	return &m_statModifier;
}

Race::UnitRace Race::getRaceType()
{
	return m_raceType;
}

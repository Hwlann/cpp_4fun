#include "Ork.h"

Ork::Ork()
{
	m_raceType = Race::UnitRace::ORK;
	m_passiveSkill = new Skill();
	m_passiveSkill->addEffect(Effect::EffectCategory::PRIMARY, new Effect(Effect::EffectType::BUFF, Effect::EffectTarget::DAMAGE, Effect::EffectModifier::PERCENT, Effect::SkillType::STRENGTH, 80, -1, true));

}

Ork::~Ork()
{
}

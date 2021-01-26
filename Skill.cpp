#include "Skill.h"


Skill::Skill(int damage, int aoe, int range) :
	m_damage(damage), m_areaOfEffect(aoe), m_range(range)
{
}

Skill::~Skill()
{

}

void Skill::addEffect(Effect::EffectCategory category, Effect* effect)
{
	switch (category) {
		case Effect::EffectCategory::PRIMARY:
			if(!m_primaryEffect) m_primaryEffect = effect;
			break;
		case Effect::EffectCategory::SECONDARY:
			if (!m_secondaryEffect) m_secondaryEffect = effect;
			break;
	}
}

Effect* Skill::getPrimaryEffect()
{
	return m_primaryEffect;
}

Effect* Skill::getSecondaryEffect()
{
	return m_secondaryEffect;
}

Effect::SkillType* Skill::getSkillType()
{
	return m_skillType;
}

int Skill::getDamage()
{
	return m_damage;
}

int Skill::getRange()
{
	return m_range;
}

int Skill::getManaCost()
{
	return m_manaCost;
}

void Skill::increaseDamage(float coef)
{
	m_damage *= coef;
}

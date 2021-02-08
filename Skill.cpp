#include "Skill.h"

Skill::Skill(int damage, Pattern* castingPattern, Pattern* aoePattern, bool applyOnAllies) :
	m_damage(damage),
	m_castingPattern(castingPattern), m_aoePattern(aoePattern),
	m_applyOnAllies(applyOnAllies)
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

bool Skill::getApplyOnAllies()
{
	return m_applyOnAllies;
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

Pattern* Skill::getCastingPattern()
{
	return m_castingPattern;
}

Pattern* Skill::getAoePattern()
{
	return m_aoePattern;
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

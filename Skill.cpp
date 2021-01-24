#include "Skill.h"


Skill::Skill(int damage, int range) :
	m_damage(damage), m_range(range)
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
			if (!m_secondaryEffet) m_secondaryEffet = effect;
			break;
	}
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

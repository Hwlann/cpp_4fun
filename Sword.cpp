#include "Sword.h"

Sword::Sword(bool isTwoHanded) :
	m_isTwoHanded(isTwoHanded)
{
	if (m_isTwoHanded) {
		m_mainSkill = new Skill(m_baseDamage * this->getTwoHandsDamageMultiplicator(), m_baseRange);
		m_mainSkill->setName("Steal Speed");
		m_mainSkill->addEffect(Effect::EffectCategory::PRIMARY, new Effect(Effect::EffectType::DEBUFF, Effect::EffectTarget::MOVEMENT, 1, 3));
		m_mainSkill->addEffect(Effect::EffectCategory::SECONDARY, new Effect(Effect::EffectType::BUFF, Effect::EffectTarget::MOVEMENT, 1, 3));

	}
	else {
		m_mainSkill = new Skill(m_baseDamage, m_baseRange);
	}
}

Sword::~Sword()
{
}

std::vector<Skill*> Sword::getSkills()
{
	return m_skills;
}

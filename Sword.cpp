#include "Sword.h"

Sword::Sword(bool isTwoHanded) :
	m_isTwoHanded(isTwoHanded)
	{
	m_weaponType = Weapon::WeaponType::SWORD;
	// MAIN SKILL
	m_mainSkill = new Skill(m_baseDamage, new Pattern(Pattern::PatternType::LINE, 1,1), new Pattern(Pattern::PatternType::LINE, 0, 1), false);
	m_mainSkill->setName("Steal Speed");
	m_mainSkill->addEffect(Effect::EffectCategory::PRIMARY, new Effect(Effect::EffectType::DEBUFF, Effect::EffectTarget::MOVEMENT, Effect::EffectModifier::FLAT, Effect::SkillType::DEXTERITY, 1, 3, true));
	m_mainSkill->addEffect(Effect::EffectCategory::SECONDARY, new Effect(Effect::EffectType::BUFF, Effect::EffectTarget::MOVEMENT, Effect::EffectModifier::FLAT, Effect::SkillType::DEXTERITY, 1, 3, true));
	// TWO HAND SWORD
	if (m_isTwoHanded) {
		m_mainSkill->increaseDamage(getTwoHandsDamageMultiplicator());
		m_weaponSize = WeaponSize::TWO_HANDS;
	}
	// ONE HAND SWORD
	else {
		m_weaponSize = WeaponSize::ONE_HAND;
		m_offHandSkill = new Skill(static_cast<int>(m_baseDamage * getoffHandsDamageMultiplicator()), new Pattern(Pattern::PatternType::LINE, 1, 1), new Pattern(Pattern::PatternType::LINE, 1, 0), false);
		m_offHandSkill->setName("SAIGNE CHAROGNE !");
		m_offHandSkill->addEffect(Effect::EffectCategory::PRIMARY, new Effect(Effect::EffectType::DEBUFF, Effect::EffectTarget::HEALTH, Effect::EffectModifier::FLAT, Effect::SkillType::STRENGTH, static_cast<int>(15*getoffHandsDamageMultiplicator()), 3, false));
		m_offHandSkill->addEffect(Effect::EffectCategory::SECONDARY, new Effect(Effect::EffectType::DEBUFF, Effect::EffectTarget::MOVEMENT, Effect::EffectModifier::FLAT, Effect::SkillType::DEXTERITY, 1, 3, true));
	}
	m_skills.push_back(m_mainSkill);
	if (m_offHandSkill != nullptr) m_skills.push_back(m_offHandSkill);
}

Sword::~Sword()
{
	for (int i = 0; i < m_skills.size(); i++) {
		if (m_skills.at(i) != nullptr) delete m_skills.at(i);
	}
}

std::vector<Skill*> Sword::getSkills()
{
	return m_skills;
}

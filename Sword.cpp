#include "Sword.h"

Sword::Sword(Skill* mainSkill, Skill* offHandSkill){
	m_mainSkill = mainSkill;
	m_offHandSkill = offHandSkill;
	m_isTwoHanded = false;
}

Sword::Sword(Skill* mainSkill, Skill* secondSkill) {
	m_mainSkill = mainSkill;
	m_secondSkill = secondSkill;
	m_isTwoHanded = true;
}

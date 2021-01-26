#include "OneHand.h"

OneHand::OneHand()
{
}

OneHand::~OneHand()
{
	if (m_offHandSkill != nullptr) delete m_offHandSkill;
}

Skill* OneHand::getOffHandSkill()
{
	return nullptr;
}

float OneHand::getoffHandsDamageMultiplicator()
{
	return m_offHandsDamageMultiplicator;
}

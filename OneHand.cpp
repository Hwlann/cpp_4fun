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
	return m_offHandSkill;
}

float OneHand::getoffHandsDamageMultiplicator()
{
	return m_offHandsDamageMultiplicator;
}

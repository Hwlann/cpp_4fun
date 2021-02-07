#include "Armour.h"

Armour::ArmorType* Armour::getArmourType()
{
	return m_armourType;
}

int Armour::getArmour() {
	return m_armour;
}

int Armour::getMagicalResistance() {
	return m_magicalResistance;
}

int Armour::getMovementPenalty() {
	return m_movementPenalty;
}

void Armour::reduceArmour(float percent) {
	m_armour -= m_maxArmor * percent;
}

void Armour::reduceMagicilResistance(float percent) {
	m_magicalResistance -= m_maxMagicialResistance * percent;
}

void Armour::buffArmour(float percent)
{
	m_armour += m_maxArmor * percent;
}

void Armour::buffMagicalResistance(float percent)
{
	m_magicalResistance += m_maxMagicialResistance * percent;
}


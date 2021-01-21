#include "Armour.h"

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

void Armour::reduceMagicialResistace(float percent) {
	m_magicalResistance -= m_maxMagicialResistance * percent;
}


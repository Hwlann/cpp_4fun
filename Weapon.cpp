#include "Weapon.h"

Weapon::Weapon(std::string name, int base_dmg, WeaponType type, int durability) :
	m_name(name),
	m_baseDamage(base_dmg),
	m_durability(durability) 
{

}

int Weapon::getDurability() {
	return m_durability;
}

int Weapon::getBaseDamage() {
	return m_baseDamage;
}

std::string Weapon::getName() {
	return m_name;
}
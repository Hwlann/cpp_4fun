#include "Weapon.h"

Weapon::~Weapon()
{
}

Weapon::WeaponType* Weapon::getWeaponType()
{
	return &m_weaponType;
}

Weapon::WeaponSize* Weapon::getWeaponSize()
{
	return &m_weaponSize;
}

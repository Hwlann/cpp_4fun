#pragma once
#ifndef DEF_WEAPON
#define DEF_WEAPON
#include <string>

class Weapon
{
	public :
		enum class WeaponType {
			AXE,
			BOW,
			STAFF
		};
		Weapon(std::string name, int base_dmg = 0, WeaponType type = WeaponType::AXE, int durability = 100);
		std::string getName();
		int getBaseDamage();
		int getDurability();

	private:
		std::string m_name;
		int m_baseDamage;
		int m_durability;
};

#endif


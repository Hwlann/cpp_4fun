#pragma once
#ifndef DEF_WEAPON
#define DEF_WEAPON
#include "Equipment.h"
#include <vector>
#include <string>

class Weapon : public Equipment
{
	public :
		enum class WeaponType {
			SWORD,
			AXE
		};

		enum class WeaponSize {
			ONE_HAND,
			TWO_HANDS
		};

		Weapon();
		virtual ~Weapon();
		WeaponType* getWeaponType();
		WeaponSize* getWeaponSize();


	private:
		WeaponType* m_weaponType = nullptr;
		WeaponSize* m_weaponSize = nullptr;

};

#endif


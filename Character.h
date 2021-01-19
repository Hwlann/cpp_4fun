#pragma once
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include <inttypes.h>
#include <iostream>
#include <map>
#include <vector>

#include "Weapon.h"

// DEFINES
constexpr int32_t WARRIOR_MAX_HP = 150;
constexpr int32_t WIZARD_MAX_HP = 70;
constexpr int32_t RANGER_MAX_HP = 95;

class Character
{
	public:
		// STRUCTURES
		struct CharacterPosition {
			int32_t x;
			int32_t y;
		};

		// ENUMS
		enum class CharacterClass {
			WARRIOR,
			WIZARD,
			RANGER
		};

		// CONSTRUCTOR & DESTRUCTOR
		Character(std::string name = "Anonyme", CharacterClass characterClass = CharacterClass::WARRIOR);
		~Character();

		// GETTER
		std::string getName();
		CharacterPosition* getPosition();
		Weapon* getWeapon();

		// SETTERS
		void setPosition(CharacterPosition* position);

		// METHODS
		void receiveDamage(int32_t hp, std::string attackerName);
		void heal(int32_t damage);
		bool isAlive();
		void attackTarget(Character *target);
		//void swapWeapon(std::string weaponName);

	private:
		// VARIABLES
		int32_t m_maxHp = 0;
		int32_t m_currentHp = 0;
		int32_t m_actionPoint = 0;
		std::string m_name;

		// LISTS
		std::vector<std::string> m_classNames = { "Warrior", "Wizard", "Ranger" };

		// OBJECTS
		Weapon* m_currentWeapon = nullptr;
		CharacterPosition* m_position = nullptr;
		CharacterClass m_characterClass;
};
#endif // DEF_PERSONNAGE




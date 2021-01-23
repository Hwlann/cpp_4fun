#pragma once
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include <inttypes.h>
#include <iostream>
#include <map>
#include <vector>

#include "Weapon.h"
#include "Armour.h"
#include "Utility.h"
#include "GameObject.h"

// DEFINES
constexpr int32_t WARRIOR_MAX_HP = 150;
constexpr int32_t WIZARD_MAX_HP = 70;
constexpr int32_t RANGER_MAX_HP = 95;

class Character : public GameObject
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
		virtual ~Character();

		// GETTER
		std::string getName();
		CharacterPosition *getPosition();
		Weapon* getWeapon();

		// SETTERS
		void setPosition(CharacterPosition* position);
		void setLeftHandWeapon(Weapon* weapon);
		void setRightHandWeapon(Weapon* weapon);
		void setArmour(Armour* armour);

		// METHODS
		void receiveDamage(int32_t damage, std::string attackerName);
		void heal(int32_t damage);
		bool isAlive();
		void attackTarget(Character *target);
		void moveAlongPath(std::vector<std::pair<int, int>> path);
		//void swapWeapon(std::string weaponName);

	protected:
		// VARIABLES
		int32_t m_maxHp = 0;
		int32_t m_currentHp = 0;
		int32_t m_actionPoint = 0;
		std::string m_name;

		// LISTS
		std::vector<std::string> m_classNames = { "Warrior", "Wizard", "Ranger" };

		// OBJECTS
		Weapon *m_leftHand = nullptr;
	    Weapon *m_rightHand = nullptr;
		Armour *m_armour = nullptr;
		CharacterPosition* m_position = nullptr;
		CharacterClass m_characterClass;
};
#endif // DEF_PERSONNAGE




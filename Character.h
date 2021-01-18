#pragma once
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include <inttypes.h>
#include <iostream>
#include <map>
#include <vector>

#include "Weapon.h"

constexpr uint16_t WARRIOR_MAX_HP = 150;
constexpr uint16_t WIZARD_MAX_HP = 70;
constexpr uint16_t RANGER_MAX_HP = 95;

class Character
{
	public:
		struct CharacterPosition {
			int x;
			int y;
		};

		enum class CharacterClass {
			WARRIOR,
			WIZARD,
			RANGER
		};
		Character(std::string name = "Anonyme", CharacterClass characterClass = CharacterClass::WARRIOR);
		~Character();
		void receiveDamage(int32_t hp, std::string attackerName);
		void heal(int32_t damage);
		bool isAlive();
		std::string getName();
		void setPosition(CharacterPosition *position);
		CharacterPosition *getPosition();
		Weapon *getWeapon();
		bool moveToTile();
		void myTurn();
		void attackTarget(Character *target);
		//void swapWeapon(std::string weaponName);

	private:
		CharacterClass m_characterClass;
		std::vector<std::string> m_classNames = { "Warrior", "Wizard", "Ranger" };
		std::string m_name;
		uint16_t m_maxHp = 0;
		int m_turnChoise;
		int16_t m_currentHp = 0;
		int m_movementPoint;
		int m_actionPoint;
		Weapon* m_currentWeapon = nullptr;
		CharacterPosition *m_position;
};


#endif // DEF_PERSONNAGE




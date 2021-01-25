#pragma once
#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include "GameObject.h"

#include <string>
#include <inttypes.h>
#include <iostream>
#include <map>
#include <vector>

#include "Weapon.h"
#include "Armour.h"
#include "Class.h"
#include "Utility.h"

// DEFINES
class Character : public GameObject
{
	public:

		// CONSTRUCTOR & DESTRUCTOR
		Character();
		virtual ~Character();

		// EFFECTS
		void addEffectToCharacter(Effect *effect);
		void applyEffects();

		// GETTER

		// SETTERS
		void setLeftHandWeapon(Weapon* weapon);
		void setRightHandWeapon(Weapon* weapon);
		void setDualHandWeapon(Weapon *weapon);
		void setArmour(Armour* armour);
		void setClass(Class* characterClass);

		// METHODS
		// HEATLH 
		void applySkill(Skill* skill);
		void takeDamage(int32_t damageAmount);
		void heal(int32_t healAmount);
		bool isAlive();

		// MOVEMENT
		void moveAlongPath(std::vector<std::pair<int, int>> path);

		// MULTIPLIERS
		float m_armorMulti = 1.0f;
		float m_magicalResistanceMulti = 1.0f;
		float m_damageMulti = 1.0f;
		float m_healthMulti = 1.0f;
		float m_manaMulti = 1.0f;
		float m_movementMulti = 1.0f;

	protected:
		// VARIABLES
		int32_t m_maxHp = 0, m_currentHp = 0;
		int32_t m_actionPoint = 0, m_maxActionPoint = 0 ;
		int32_t m_movementPoint = 0, m_maxMovementPoint = 0;
		float m_dodgeRate = 0.0f, precision = 0.0f;

		// OBJECTS
		Weapon *m_leftHand = nullptr;
	    Weapon *m_rightHand = nullptr;
		Armour *m_armour = nullptr;
		Class *m_class = nullptr;
		std::vector<Effect*> m_effectList;
		std::map<std::string, int> m_effectRemainingTurns;
};
#endif // DEF_PERSONNAGE




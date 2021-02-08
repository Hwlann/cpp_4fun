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
#include "Race.h"
#include "Utility.h"

class Character : public GameObject
{
	public:

		// CONSTRUCTOR & DESTRUCTOR
		Character();
		Character(Class* characterClass, Race* race, Weapon* leftHand, Weapon* rightHand, Armour* armour = nullptr);
		virtual ~Character();

		void attackTarget(Character *source, Character* target, Skill* skill);

		// EFFECTS
		void addEffectToCharacter(Effect *effect);
		void applyEffects();

		// GETTER
		Weapon* getWeapon();
		Class::UnitClass* getClass();
		Race::UnitRace* getRace();
		int8_t getTeamNumber();

		// SETTERS
		void setTeamNumber(int8_t teamNumber);

		void setMaxHp(int maxHp);
		void setMaxMana(int maxMana);
		void setMaxActionPoint(int maxAP);
		void setMaxMovementPoint(int maxMP);
		void setDodgeRate(float dodgeRate);
		void setPrecision(float precision);
			
		void setLeftHandWeapon(Weapon* weapon);
		void setRightHandWeapon(Weapon* weapon);
		void setDualHandWeapon(Weapon *weapon);
		void setArmour(Armour* armour);
		void setClass(Class* characterClass);
		void setRace(Race* race);

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
		int32_t m_currentHp = 0, m_maxHp = 0;
		int32_t m_currentMana = 0, m_maxMana = 0;
		int32_t m_actionPoint = 0, m_maxActionPoint = 0 ;
		int32_t m_movementPoint = 0, m_maxMovementPoint = 0;
		float m_dodgeRate = 0.0f, m_precision = 0.0f;
		int8_t m_teamNumber;

		// OBJECTS
		Class* m_class = nullptr;
		Race* m_race = nullptr;
		Weapon *m_leftHand = nullptr;
	    Weapon *m_rightHand = nullptr;
		Armour *m_armour = nullptr;

		std::vector<Effect*> m_effectList;
		std::map<std::string, int> m_effectRemainingTurns;

};
#endif // DEF_PERSONNAGE




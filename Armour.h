#pragma once
#ifndef DEF_ARMOUR
#define DEF_ARMOUR
#include "Equipment.h"

class Armour : public Equipment
{
	public:
		enum class ArmorType { CLOTH, LEATHER, CHAINMAIL, PLATE };
		ArmorType* getArmourType();
		int getArmour();
		int getMagicalResistance();
		int getMovementPenalty();

		void reduceArmour(float percent);
		void reduceMagicilResistance(float percent);

		void buffArmour(float percent);
		void buffMagicalResistance(float percent);


	protected:
		int m_maxArmor;
		int m_armour;
		int m_maxMagicialResistance;
		int m_magicalResistance;
		int m_movementPenalty;

		ArmorType* m_armourType = nullptr;
};
#endif // !DEF_ARMOUR


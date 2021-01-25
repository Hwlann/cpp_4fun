#pragma once
#ifndef DEF_ARMOUR
#define DEF_ARMOUR
class Armour
{
	protected:
		int m_maxArmor;
		int m_armour;
		int m_maxMagicialResistance;
		int m_magicalResistance;
		int m_movementPenalty;

	public:
		enum class ArmorType { CLOTH, LEATHER, CHAINMAIL, PLATE };
		int getArmour();
		int getMagicalResistance();
		int getMovementPenalty();

		void reduceArmour(float percent);
		void reduceMagicilResistance(float percent);

		void buffArmour(float percent);
		void buffMagicalResistance(float percent);
};
#endif // !DEF_ARMOUR


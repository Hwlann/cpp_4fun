#include "Character.h"

Character::Character()
{

}
void Character::moveAlongPath(std::vector<std::pair<int, int>> path)
{

}

Character::~Character() {
	if (m_leftHand != nullptr) delete m_leftHand;
	if (m_rightHand != nullptr) delete m_rightHand;
	if (m_armour != nullptr) delete m_armour;
}

bool Character::isAlive() {
	if (m_currentHp > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Character::receiveDamage(int32_t damage, std::string attackerName) {
	Utility::clamp(&damage, 0, m_maxHp);;
	std::cout << "\n\n> " << m_name <<" Outch !\n" << attackerName << " Attacked me ! Lost " << damage << " hp !" <<std::endl;
}

void Character::heal(int32_t damage) {
	Utility::clamp(&damage, 0, m_maxHp);
}
void Character::setLeftHandWeapon(Weapon* weapon)
{
}

void Character::setRightHandWeapon(Weapon* weapon)
{
}

void Character::setArmour(Armour* armour)
{
}
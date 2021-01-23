#include "Character.h"

Character::Character()
{

}

Character::~Character() {
	if (m_leftHand != nullptr) delete m_leftHand;
	if (m_rightHand != nullptr) delete m_rightHand;
	if (m_armour != nullptr) delete m_armour;
	if (m_class != nullptr) delete m_class;
}


void Character::moveAlongPath(std::vector<std::pair<int, int>> path)
{

}


bool Character::isAlive() {
	if (m_currentHp > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Character::receiveDamage(int32_t damage)
{
	
}

void Character::heal(int32_t healAmout) {
	m_currentHp += healAmout;
	Utility::clamp(&m_currentHp, 0, m_maxHp);
}

void Character::setLeftHandWeapon(Weapon* weapon)
{
	m_leftHand = weapon;
}

void Character::setRightHandWeapon(Weapon* weapon)
{
	m_rightHand = weapon;
}

void Character::setDualHandWeapon(Weapon* weapon)
{
	m_leftHand = weapon;
	m_rightHand = weapon;
}

void Character::setArmour(Armour* armour)
{
	m_armour = armour;
}

void Character::setClass(Class* characterClass)
{
	m_class = characterClass;
}

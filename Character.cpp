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

void Character::addEffectToCharacter(Effect* effect)
{
	bool alreadyExist= false;
	for (int i = 0; i < m_effectList.size(); i++) {
		if (m_effectList.at(i)->getName() == effect->getName()) {
			alreadyExist = true;
			m_effectRemainingTurns.at(effect->getName()) = effect->getNbTurns();
		}
	}
	if (!alreadyExist) {
		m_effectList.push_back(effect);
		m_effectRemainingTurns.insert(std::pair < std::string, int>(effect->getName(), effect->getNbTurns()));
	}
}

void Character::applyEffect(Effect* effect)
{

}

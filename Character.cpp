#include "Character.h"


Character::Character(std::string name, CharacterClass characterClass) :
	m_name(name),
	m_characterClass(characterClass)
{
	std::cout << "I'm " << m_name << std::endl;
	switch (m_characterClass) {
		case CharacterClass::WARRIOR:
			m_maxHp = WARRIOR_MAX_HP;
			std::cout << "A Powerfull " << m_classNames.at(0) << std::endl;
			m_currentWeapon = new Weapon("BFAxe", 110, Weapon::WeaponType::AXE, 100);
			break;
		case CharacterClass::WIZARD:
			m_maxHp = WIZARD_MAX_HP;
			std::cout << "A Powerfull " << m_classNames.at(1) << std::endl;
			m_currentWeapon = new Weapon("BFStaff", 90, Weapon::WeaponType::STAFF, 60);
			break;
		case CharacterClass::RANGER:
			m_maxHp = RANGER_MAX_HP;
			std::cout << "A Powerfull " << m_classNames.at(2) << std::endl;
			m_currentWeapon =  new Weapon("BFBow", 70, Weapon::WeaponType::BOW, 80);
			break;
	}
	m_currentHp = m_maxHp;
	m_actionPoint = 2;
	m_movementPoint = 1;
	std::cout << std::endl;
}

void Character::attackTarget(Character *target) {
	target->receiveDamage(m_currentWeapon->getBaseDamage(), m_name);
}

Character::~Character() {
	if (m_currentWeapon != nullptr) delete m_currentWeapon;
	/*
	for (std::map<std::string, Weapon *>::iterator it = m_weaponList.begin(); it != m_weaponList.end(); ++it) {
		delete it->second;
	}
	*/
}

bool Character::isAlive() {
	if (m_currentHp > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Character::receiveDamage(int32_t hp, std::string attackerName) {
	m_currentHp -= hp;
	std::cout << "\n\n> " << m_name <<" Outch !\n" << attackerName << " Attacked me ! Lost " << hp << " hp !" <<std::endl;
}

void Character::heal(int32_t damage) {
	m_currentHp += damage;
}

Weapon* Character::getWeapon() {
	return m_currentWeapon;
}

/*
void Character::swapWeapon(std::string weaponName) {
	if (m_weaponList.at(weaponName)) {
		m_currentWeapon = m_weaponList.at(weaponName);
	}
}
*/

void Character::setPosition(CharacterPosition *position) {
	m_position = position;
}

Character::CharacterPosition* Character::getPosition() {
	return m_position;
}

bool Character::moveToTile() {
	if(m_movementPoint > 0) {
		return true;
	}
	else return false;
}

void Character::myTurn() {
	std::cout << m_name << " Turn !\n";
	std::cout << "1 - Attack\n" << "2 - Drink Health Potion!\n" << "3 - Move\n";
	std::cout << "Action : ";
	std::cin >> m_turnChoise;
}

std::string Character::getName() {
	return m_name;
}
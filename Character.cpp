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

void Character::attackTarget(Character *source, Character* target, Skill * skill)
{
	std::cout << source->getName() << " use " << skill->getName() << " on " << target->getName() << " " << std::endl;
	target->applySkill(skill);
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

void Character::applySkill(Skill *skill) {
	takeDamage(skill->getDamage());
	this->addEffectToCharacter(skill->getPrimaryEffect());
	this->addEffectToCharacter(skill->getSecondaryEffect());
}

void Character::takeDamage(int32_t damageAmount)
{
	std::cout << "> " << m_name << " Outch\n";
	m_currentHp -= damageAmount;
	Utility::clamp(&m_currentHp, 0, m_maxHp);
}

void Character::heal(int32_t healAmount) {
}

void Character::setMaxHp(int maxHp)
{
	m_maxHp = maxHp;
}

void Character::setMaxMana(int maxMana)
{
	m_maxMana = maxMana;
}

void Character::setMaxActionPoint(int maxAP)
{
	m_maxActionPoint = maxAP;
}

void Character::setMaxMovementPoint(int maxMP)
{
	m_maxMovementPoint = maxMP;
}

void Character::setDodgeRate(float dodgeRate)
{
	m_dodgeRate = dodgeRate;
}

void Character::setPrecision(float precision)
{
	m_precision = precision;
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
	bool alreadyExist = false;
	// RESET TURN TIMER IF EFFECT ALREADY EXISTS
	for (int i = 0; i < m_effectList.size(); i++) {
		if (m_effectList.at(i)->getName() == effect->getName()) {
			alreadyExist = true;
			m_effectRemainingTurns.at(effect->getName()) = effect->getNbTurns();
		}
	}
	// ADD EFFECT
	if (!alreadyExist) {
		m_effectList.push_back(effect);
		m_effectRemainingTurns.insert(std::pair < std::string, int>(effect->getName(), effect->getNbTurns()));
	}
}

void Character::applyEffects()
{
	bool isPositive = false;
	// ITERATE OVER ALL EFFETCS ON CHAR
	for (int i = 0; i < m_effectList.size(); i++) {
		if (m_effectRemainingTurns.at(m_effectList.at(i)->getName()) > 0){
			// FILTER BUFF & DEBUFF
			if (*(m_effectList.at(i)->getEffectType()) == Effect::EffectType::BUFF) isPositive = true;				
			switch (*(m_effectList.at(i)->getEffectTarget())) {
				// EFFECT ON ARMOR
				case Effect::EffectTarget::ARMOR :
					isPositive == true ? m_armorMulti += m_effectList.at(i)->getAmount() / 100 : m_armorMulti -= m_effectList.at(i)->getAmount() / 100;
					break;
				// EFFECT ON MAGICAL RESISTANCE
				case Effect::EffectTarget::MAGICAL_RESISTANCE:
					isPositive == true ? m_magicalResistanceMulti += m_effectList.at(i)->getAmount() / 100 : m_magicalResistanceMulti -= m_effectList.at(i)->getAmount() / 100;
					break;
				// EFFECT ON DAMAGE
				case Effect::EffectTarget::DAMAGE :
					isPositive == true ? m_damageMulti += m_effectList.at(i)->getAmount() / 100 : m_damageMulti -= m_effectList.at(i)->getAmount() / 100;
					break;
				// EFFECT ON HEALTH (HOT / DOT)
				case Effect::EffectTarget::HEALTH :
					isPositive == true ? m_currentHp += m_effectList.at(i)->getAmount() : m_currentHp -= m_effectList.at(i)->getAmount();
					break;
				// EFFECT ON MANA
				case Effect::EffectTarget::MANA :
					isPositive == true ? m_manaMulti += m_effectList.at(i)->getAmount() / 100 : m_manaMulti -= m_effectList.at(i)->getAmount() / 100;
					break;
				// EFFECT ON MOVEMENT
				case Effect::EffectTarget::MOVEMENT :
					isPositive == true ? m_movementMulti += m_effectList.at(i)->getAmount() / 100 : m_movementMulti -= m_effectList.at(i)->getAmount() / 100;
					break;
			}
		}
		// DECREMENT TURN TIME
		m_effectRemainingTurns.at(m_effectList.at(i)->getName())--;
		if (m_effectRemainingTurns.at(m_effectList.at(i)->getName()) == 0) {
			// REMOVE FROM LISTS IF TURN = 0
			m_effectRemainingTurns.erase(m_effectList.at(i)->getName());
			m_effectList.erase(m_effectList.begin()+i);
		}
	}
}

Weapon* Character::getWeapon()
{
	return m_rightHand;
}

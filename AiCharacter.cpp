#include "AiCharacter.h"

AiCharacter::AiCharacter()
{
}

AiCharacter::~AiCharacter()
{
	if (m_forcetarget != nullptr) delete m_forcetarget;
}

void AiCharacter::applyDifficulty()
{

}

void AiCharacter::moveToClosestLocationFromTarget(Character* target)
{
}

void AiCharacter::moveToSafeLocation()
{
}

void AiCharacter::moveToClosestLocationFromTargetWithSafestPath()
{
}

void AiCharacter::setForceTarget(Character* target)
{
	if (target->getName() != this->getName()) {
		std::cout << this->getName() << " - Orders reveived, new target is : " << target->getName() << std::endl;
		m_forcetarget = target;
	}
	else {
		std::cout << this->getName()  << " - WTF BRUH IMA IN UR TEAM" << std::endl;
	}
}

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
}

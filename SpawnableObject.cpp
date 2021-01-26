#include "SpawnableObject.h"

SpawnableObject::SpawnableObject()
{
}

SpawnableObject::~SpawnableObject()
{
}

int SpawnableObject::getDisplayedAsciiCode()
{
	return m_displayedAsciiCode;
}

void SpawnableObject::setDisplayedAsciiCode(int displayedAsciiCode)
{
	m_displayedAsciiCode = displayedAsciiCode;
}

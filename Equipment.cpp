#include "Equipment.h"

Equipment::Equipment()
{
}

Equipment::~Equipment()
{
	if (m_mainSkill != nullptr) delete m_mainSkill;
}

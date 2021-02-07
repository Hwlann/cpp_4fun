#include "Equipment.h"

Equipment::Equipment()
{
}

Equipment::~Equipment()
{
	if (m_mainSkill != nullptr) delete m_mainSkill;
}

Skill* Equipment::getMainSkill()
{
	return m_mainSkill;
}

Equipment::EquipmentType* Equipment::getEquipmentType()
{
	return m_equipmentType;
}

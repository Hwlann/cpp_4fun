#pragma once
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT
#include "GameObject.h"
#include "Skill.h"
class Equipment : public GameObject
{
	public:
		enum class EquipmentType {
			ARMOUR,
			WEAPON
		};

		Equipment();
		virtual ~Equipment();
		Skill* getMainSkill();
		EquipmentType* getEquipmentType();

	protected:
		Skill *m_mainSkill = nullptr;
		EquipmentType* m_equipmentType = nullptr;
};
#endif

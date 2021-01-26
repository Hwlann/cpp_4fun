#pragma once
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT
#include "GameObject.h"
#include "Skill.h"
class Equipment : public GameObject
{
	public:
		Equipment();
		virtual ~Equipment();

		Skill* getMainSkill();

	protected:
		Skill *m_mainSkill = nullptr;
};
#endif

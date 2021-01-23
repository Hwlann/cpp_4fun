#pragma once
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT
#include "GameObject.h"
#include "Skill.h"
class Equipment : public GameObject
{
	public:

	protected:
		Skill *m_mainSkill;
};
#endif

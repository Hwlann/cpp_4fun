#pragma once
#ifndef DEF_CHIEF
#define DEF_CHIEF
#include "AiCharacter.h"
#include <vector>
template <class T>
class Chief : public AiCharacter
{
	public:
		Chief(std::vector<T *> list);
		Chief();
		virtual ~Chief();
		float getChiefStatsModifier();
		void setDesignHordeTarget(Character* target);
		void setHordeList(std::vector<T *> horde);

	private:
		float m_chiefStatsModifier = 2.0f;
		std::vector<T *> m_hordeList;

};
#endif // !DEF_CHIEF

template<class T>
inline Chief<T>::Chief(std::vector<T *> list)
{
}

template<class T>
inline Chief<T>::Chief()
{
	this->setMaxHp(m_maxHp * m_chiefStatsModifier);
	std::cout << " MAX HP : " << m_maxHp << std::endl;;
}

template<class T>
inline Chief<T>::~Chief()
{
}

template<class T>
inline float Chief<T>::getChiefStatsModifier()
{
	return m_chiefStatsModifier;
}

template<class T>
inline void Chief<T>::setDesignHordeTarget(Character* target)
{
	if (m_hordeList.size() > 0) {
		for (int i = 0; i < m_hordeList.size(); i++) {
			dynamic_cast<AiCharacter *>(m_hordeList.at(i))->setForceTarget(target);
		}
	}
}

template<class T>
inline void Chief<T>::setHordeList(std::vector<T *> horde)
{
	if (horde.size() > 0) {
		for (int i = 0; i < horde.size(); i++) {
			if (dynamic_cast<Character*>(horde.at(i))->getName() != this->getName())
			{
				m_hordeList.push_back(horde.at(i));
				std::cout << "JOINED MY HORDE : " << dynamic_cast<Character*>(horde.at(i))->getName() << std::endl;
			}
		}
	}
}

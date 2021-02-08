#pragma once
#ifndef DEF_CHIEF
#define DEF_CHIEF
#include "AiCharacter.h"
#include <vector>
template <class T>
class Chief : public AiCharacter
{
	public:
		Chief(std::vector<T> list);
		Chief();
		virtual ~Chief();
		float getChiefStatsModifier();
		void setDesignHordeTarget(Character* target);

	private:
		float m_chiefStatsModifier = 2.0f;
		std::vector<T> m_list;

};
#endif // !DEF_CHIEF

template<class T>
inline Chief<T>::Chief(std::vector<T> list)
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
	if (m_list.size() > 0) {
		for (int i = 0; i < m_list.size(); i++) {
			//dynamic_cast<AiCharacter*>(m_list.at(i))->setForceTarget(target);
		}
	}
}

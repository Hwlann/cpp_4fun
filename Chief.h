#pragma once
#ifndef DEF_CHIEF
#define DEF_CHIEF
#include "AiCharacter.h"
#include <vector>
#include "Sound.h"

template <class T>
class Chief : public AiCharacter
{
	public:
		Chief();
		Chief(std::vector<T *> list);
		virtual ~Chief();
		float getChiefStatsModifier();
		void setDesignHordeTarget(Character* target);
		void setHordeList(std::vector<T *> horde);
		std::vector<T*> getHordeList();

	private:
		float m_chiefStatsModifier = 2.0f;
		std::vector<T *> m_hordeList;

};
#endif // !DEF_CHIEF

template<class T>
inline Chief<T>::Chief(std::vector<T *> list)
{
	setHordeList(list);
}

template<class T>
inline Chief<T>::Chief()
{

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
	if (this->getUnitEnumRace() == Race::UnitRace::ORK) std::cout << "\n\tWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAGH\n" << std::endl;
	Sound::playWaghSound();
	std::cout << this->getName() << " - Destroy this felow kiddo : " << target->getName() << std::endl;
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
		for (int i = horde.size() ; i-- ; ) {
			if (dynamic_cast<Character*>(horde.at(i))->getName() != this->getName())
			{
				m_hordeList.push_back(horde.at(i));
			}
		}
	}
}

template<class T>
inline std::vector<T*> Chief<T>::getHordeList()
{
	std::cout << this->getName() << "'s Horde : " << std::endl;
	if (m_hordeList.size() > 0) {
		for (int i = 0 ; i < m_hordeList.size() ; i++) {
			std::cout << i+1 << " - " << dynamic_cast<Character*>(m_hordeList.at(i))->getName() << std::endl;
		}
	}
	return m_hordeList;
}

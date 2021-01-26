#pragma once
#ifndef DEF_SPAWNABLE_OBJECT
#define DEF_SPAWNABLE_OBJECT
#include "GameObject.h"

class SpawnableObject : public GameObject
{
	public:
		SpawnableObject();
		virtual ~SpawnableObject();
		int getDisplayedAsciiCode();
		void setDisplayedAsciiCode(int displayedAsciiCode);

	private:
		int m_displayedAsciiCode = 0;

};
#endif


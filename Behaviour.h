#pragma once
#ifndef DEF_BEHAVIOUR
#define DEF_BEHAVIOUR
#include "GameObject.h"
class Behaviour : public GameObject
{
	public:
		enum class AiBehaviourType {
			LEROY_JENKINS,
			HIT_AND_RUN,
			E_GIRL,
			PLAY_MAKER
		};

	private:


};
#endif

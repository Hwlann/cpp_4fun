#pragma once
#ifndef DEF_GAME_OBJECT
#define DEF_GAME_OBJECT
#include <string>
class GameObject
{
	public:
		GameObject(std::string name = "N/C");
		virtual ~GameObject();
		std::string getName();
	protected:
		std::string m_name;
};
#endif


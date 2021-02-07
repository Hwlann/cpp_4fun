#pragma once
#ifndef DEF_GAME_OBJECT
#define DEF_GAME_OBJECT
#include <string>

#define MAX(a, b) (a > b ? a : b);
#define MIN(a, b) (a < b ? a : b);

class GameObject
{
	public:
		GameObject(std::string name = "N/C");
		virtual ~GameObject();
		std::string getName();
		void setName(std::string name);

	protected:
		std::string m_name;
};
#endif


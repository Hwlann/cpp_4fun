#pragma once
#ifndef DEF_GAME_OBJECT
#define DEF_GAME_OBJECT
#include <string>
class GameObject
{
public:
	std::string getName();
protected:
	std::string m_name;

};
#endif


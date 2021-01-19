#pragma once
#ifndef DEF_UTILITY
#define DEF_UTILITY

#include <cstring>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

class Utility
{
	public:
		static void clamp(int* valueAddr, int min, int max);
		static std::string pritnT(std::string str, std::map<std::string, int*> myMap);
};

#endif // !* DEF_UTILITY


#pragma once
#ifndef DEF_UTILITY
#define DEF_UTILITY

#include <cstring>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

class Utility
{
public:
	static void clamp(int* valueAddr, int min, int max);
	static float distance(std::pair<int, int> origin, std::pair<int, int> destination);
	static std::string printT(std::string str, std::map<std::string, int*> myMap);
	static std::string printT(std::string str, std::map<std::string, std::string*> myMap);
	static std::vector<std::pair<int, int>> getPath(std::pair<int, int> origin, std::pair<int, int> destination);
};

#endif // !* DEF_UTILITY
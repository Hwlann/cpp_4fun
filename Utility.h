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
#include <fstream>
#include <limits>

class Utility
{
public:
	static void clamp(int* valueAddr, int min, int max);
	static float distance(std::pair<int, int> origin, std::pair<int, int> destination);
	static std::string printT(std::string str, std::map<std::string, int*> myMap);
	static std::string printT(std::string str, std::map<std::string, std::string*> myMap);
	static std::vector<std::pair<int, int>> getPath(std::pair<int, int> origin, std::pair<int, int> destination);
	static bool writeToFile(char const* filename, unsigned lineNo, std::string toWrite);
};

#endif // !* DEF_UTILITY
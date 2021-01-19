#include "Utility.h"

int Utility::clamp(int val, int min, int max) {
	if (val > max / 2)	return val > max ? max : val;
	else return val < min ? min : val;
}
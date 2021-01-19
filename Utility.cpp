#include "Utility.h"

void Utility::clamp(int *valueAddr, int val, int min, int max) {
	if(val  > max) std::memset(valueAddr, val, sizeof(max));
	else if(val < min) std::memset(valueAddr, val, sizeof(min));
	else std::memset(valueAddr, val, sizeof(val));	
}
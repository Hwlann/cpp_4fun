#include "Utility.h"

void Utility::clamp(int *valueAddr, int min, int max) {
	if ((*valueAddr) > max) (*valueAddr) = max;
	else if ((*valueAddr) < min) (*valueAddr) = min;
}
#include "Sound.h"

void Sound::playWaghSound()
{
	PlaySound(TEXT("waaagh.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

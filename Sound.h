#pragma comment(lib, "winmm.lib")
#include "GameObject.h"

#include <windows.h>
#include <mmsystem.h>

class Sound :
    public GameObject
{
    public:
        static void playWaghSound();

    private:
};


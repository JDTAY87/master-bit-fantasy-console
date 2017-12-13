#ifndef MBAUDIO_H
#define MBAUDIO_H
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

class mbAudio
{
    public:
        mbAudio();
        void* getaudiodata();
        ~mbAudio();

    protected:

    private:
        Sint8 audiodata[4000];
};

#endif // MBAUDIO_H

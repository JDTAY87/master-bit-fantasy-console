#ifndef MBAUDIO_H
#define MBAUDIO_H
#include <stdio.h>
#include <SDL2/SDL.h>

class mbAudio
{
    public:
        mbAudio();
        void* getaudiodata();
        ~mbAudio();

    protected:

    private:
        Uint8 audiodata[4096];
};

#endif // MBAUDIO_H

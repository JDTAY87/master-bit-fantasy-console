#include "mbaudio.h"

mbAudio::mbAudio()
{
    for ( int z = 0; z < 4096; z += 64 )
    {
        for ( int z2 = (-32); z2 < 32; z2++ )
        {
            int y = (-1)*z2*z2;
            if ( y != 0 ) { audiodata[z+z2+32] = y / 16 + 64; }
        }
    }
}

void* mbAudio::getaudiodata()
{
    return &audiodata[0];
}

mbAudio::~mbAudio()
{
    //dtor
}

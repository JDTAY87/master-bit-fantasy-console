#include "mbaudio.h"

mbAudio::mbAudio()
{
    for ( int z = 0; z < 4000; z += 50 )
    {
        for ( int z2 = 0; z2 < 50; z2++ )
        {
            audiodata[z+z2] = (Sint8)( 127*sin(2*3.14159*z2/50.0) );
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

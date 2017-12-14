#include "mbaudio.h"

mbAudio::mbAudio()
{
    int halfsteps = (-9);
    double wavelength = 22050 / ( 440 * pow( 1.05946, halfsteps ) );
    for ( int z = 0; z < 4000; z++ )
    {
        audiodata[z] = (Sint8)( 127*sin( (2*3.14159*z)/wavelength ) );
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

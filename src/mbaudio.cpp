#include "mbaudio.h"

mbAudio::mbAudio()
{
    int halfsteps = 9;
    double wavelength = 22050 / ( 440 * pow( 1.05946, halfsteps ) );
    double phase = 0;
    for ( int z = 0; z < 4000; z += 200 )
    {
        for ( int z2 = 0; z2 < 200; z2++ )
        {
            audiodata[z+z2] = (Sint8)( 127*sin( (2*3.14159*(z2+phase))/wavelength ) );
        }
        phase = fmod( phase+200, wavelength );
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

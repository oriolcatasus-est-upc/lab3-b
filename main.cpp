#include "mbed.h"

PwmOut x(p21);
PwmOut y(p22);

AnalogIn adcx(p15);
AnalogIn adcy(p20);

float resistenciaX = 111.1f;
float condensadorX = 0.000001f;
float tauX;
float resistenciaY = 111.1f;
float condensadorY = 0.000001f;
float tauY;

int WAIT_TIME = 1;

// main() runs in its own thread in the OS
int main()
{
    tauX = resistenciaX * condensadorX;
    tauY = resistenciaY * condensadorY;

    x.period(tauX);
    y.period(tauY);

    while(1) {

        x.write(adcx.read()); 
        y.write(adcy.read()); 

        thread_sleep_for(WAIT_TIME);
    }
}


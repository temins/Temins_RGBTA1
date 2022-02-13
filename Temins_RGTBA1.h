#ifndef Temins_RGTBA1_h
#define Temins_RGTBA1_h

#include "Arduino.h"

class Temins_RGTBA1
{
    public:
    Temins_RGTBA1(uint8_t pin, float volume, float luas, long jeda);
    int getTip();
    float getVolumeNow();
    float getLastVolume();
    double getLastRainFall();
    double getRainFallNow();
    static void (reset)(void);
  private:
    int _pin;
    float _volume=0.002750;
    float _luas=0.020096;
   // long _jeda=1;
    static void tipping(void);
};

#endif
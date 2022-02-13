#include "Arduino.h"
#include "Temins_RGTBA1.h"
#include "TimerOne.h"

volatile int jumlah_tip;
static float last_Volume;
static float volume_Now;
static long _jeda=1;
static long patokan,patokan2;
static double last_Rainfall;
static double rainFall_Now;

Temins_RGTBA1::Temins_RGTBA1(uint8_t pin, float volume, float luas, long jeda) {
    _pin = pin;
    _volume = volume;
    _jeda = jeda;
    _luas = luas;
    pinMode(_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_pin), tipping, FALLING);	
    Timer1.initialize(1000000);
  	Timer1.attachInterrupt(reset);
    patokan,patokan2=millis();
}

void Temins_RGTBA1::tipping(void) {
	if (millis()-patokan2>100){
		jumlah_tip++;
	}
 patokan2=millis();
}

int Temins_RGTBA1::getTip(){
	return jumlah_tip;
}

float Temins_RGTBA1::getVolumeNow(){
	volume_Now = jumlah_tip*_volume;
	return volume_Now;
}

float Temins_RGTBA1::getLastVolume(){
	return last_Volume;
}

double Temins_RGTBA1::getRainFallNow(){
	rainFall_Now = jumlah_tip*_volume*1/_luas;
	return rainFall_Now;
}
double Temins_RGTBA1::getLastRainFall(){
	return last_Rainfall;
}

void Temins_RGTBA1::reset(void){
	if ((millis()-patokan)>_jeda*60000){
		last_Volume = volume_Now;
		last_Rainfall = rainFall_Now;
		jumlah_tip=0;
		patokan=millis();
	}
}

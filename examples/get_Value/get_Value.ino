#include <Temins_RGTBA1.h>

Temins_RGTBA1 TB(2, 0.025, 0.005024, 2); //pin, volume in litre, surface area in meter, reset time in minute

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tip = TB.getTip();
  double Volume = TB.getVolumeNow();
  double RF = TB.getRainFallNow();
  double LastRF = TB.getLastRainFall();
  Serial.print("Tip : ");
  Serial.println(tip);
  Serial.print("Volume : ");
  Serial.println(Volume);
  Serial.print("RF : ");
  Serial.print(RF);
  Serial.println(" mm");
  Serial.print("Last RF : ");
  Serial.print(LastRF);
  Serial.println(" mm");
  delay(1000);
}

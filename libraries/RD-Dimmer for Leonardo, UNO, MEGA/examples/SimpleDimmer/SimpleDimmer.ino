/*
  The following sketch is using setPower function to set dimming value from 0 to 100%

  Dimmer is connected to following pins:
  D2 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user
  
*/

#include <RBDdimmer.h>

dimmerLamp dimmer4(4); //initialase port for dimmer: name(PinNumber);

void setup() {
  Serial.begin(9600);
  dimmer4.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("--- Simple dimmer example ---");
  //dimmer4.setState(ON); // setState(ON/OFF);
}
void loop() {
  // put your main code here, to run repeatedly:
  dimmer4.setPower(90); // setPower(0-100%);
  delay(1000);
  dimmer4.setPower(10); // setPower(0-100%);
  delay(1000);
}

/*
  The following sketch is meant to define by function the smooth changes of dimming values in a range of values defined by user 
  values are defined in range from 0 to 100%

  Dimmer is connected to following pins:
  D2 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user
  
*/

#include <RBDdimmer.h>

dimmerLamp dimmer(4); //initialase port for dimmer: name(PinNumber);

void setup() {
  Serial.begin(9600);
  dimmer.begin(TOGGLE_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("--- Toggle dimmer example ---");
  dimmer.toggleSettings(0, 100); //Name.toggleSettings(MIN, MAX);
  dimmer.setState(ON); // state: dimmer1.setState(ON/OFF);
  pinMode(14, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:

}

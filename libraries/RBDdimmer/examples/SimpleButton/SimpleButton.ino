/*
  The following sketch is meant to turn the lamp on/off with use of a button.
  pinMode(14, INPUT); button is connected to 14th pin 

  Dimmer is connected to following pins:
  D2 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user

   void loop()  ON/OFF button evaluator of dimmer in dim4.setState(ON/OFF);
*/

#include <RBDdimmer.h>

dimmerLamp dim4(4); //initialase port for dimmer: name(PinNumber);

int buttonRed = 0;

void setup() {
  dim4.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  dim4.setPower(50); //name.setPower(0-100%); 
  pinMode(14, INPUT);
}

void loop() {
  buttonRed = digitalRead(14);  
  if (buttonRed == 1)
  {
    delay(10);
    dim4.setState(ON); //name.setState(ON/OFF);
  }  
  if (buttonRed == 0)
  {
    delay(10);
    dim4.setState(OFF); //name.setState(ON/OFF);
  }
}

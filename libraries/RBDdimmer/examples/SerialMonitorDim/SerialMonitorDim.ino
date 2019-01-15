/*
  The following sketch is meant to define the dimming value through the serial port of the controller, 
  using Serial.begin 

  Dimmer is connected to following pins:
  D2 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user

   void printSpace() function is used for adding of space after functional data
   void loop()  serial port evaluator, used to register and define values in dimmer.setPower(outVal);
*/

#include <RBDdimmer.h>//

dimmerLamp dimmer(4); //initialase port for dimmer: name(PinNumber);

int outVal = 0;

void setup() {
  Serial.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  Serial.println("Dimmer Program is starting...");
  Serial.println("Set value");
}

void printSpace(int val)
{
  if ((val / 100) == 0) Serial.print(" ");
  if ((val / 10) == 0) Serial.print(" ");
}

void loop() {
  int preVal = outVal;

  if (Serial.available())
  {
    int buf = Serial.parseInt();
    if (buf != 0) outVal = buf;
    delay(200);
  }
  dimmer.setPower(outVal); // setPower(0-100%);

  if (preVal != outVal)
  {
    Serial.print("% lampValue -> ");
    printSpace(dimmer.getPower());
    Serial.print(dimmer.getPower());

  }
  delay(50);

}

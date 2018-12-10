/*
  The following sketch is meant to smoothly turn the dimmer ON after pressing the first button and turn it OFF after pressing a second one
 
  Dimmer is connected to following pins:
  D2 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user
*/

#include <RBDdimmer.h>

#define LAMPMAXVALUE 100

dimmerLamp dimmer(4); //initialase port for dimmer: name(PinNumber);

int stateL = 0, valLamp;
int DIM4 = 0;
int mainLamp = 0;
int buttonRed = 0; 
int buttonBlue = 0; 
bool setLamp = true;

void setup() {  
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
}

//  evaluator of values that are saved in dimmer.setPower();
void RiseFallLamp(bool RiseFallInt)
{
  if ((RiseFallInt == true) && (mainLamp < LAMPMAXVALUE)) mainLamp++;
  else if ((RiseFallInt != true) && (mainLamp > 0)) mainLamp--;
}

//lamp state evaluator (ON/OFF)
bool setLampState(int val)
{
  bool ret;
  if (val >= 1) ret = true;
  else ret = false;
  return ret;
}

//button state evaluator
void readButtonState()
{
  buttonRed = digitalRead(14);
  buttonBlue = digitalRead(15);
  
  if (buttonRed < 1) stateL++;
  if (buttonBlue < 1) stateL--;
  if (stateL < 0) stateL = 0;
  if (stateL > 1) stateL = 1;
}

void loop() {
  readButtonState();
  dimmer.setPower(mainLAMP); // setPower(0-100%);
  RiseFallLamp(setLampState(stateL));
  delay(25);
}

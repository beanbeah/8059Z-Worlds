#include "main.h"
double encdL = 0, encdR = 0;
int intakeColorValue = 0, shootColorValue = 0;
void Sensors(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Rotation lRot(lRotPort);
  Rotation rRot(rRotPort);
  ADIAnalogIn intakeColor (intakeColorPort);
  ADIAnalogIn shootColor (shootColorPort);
  while(true){
    encdL = lRot.get_position();
    encdR = rRot.get_position();
    intakeColorValue = intakeColor.get_value();
    shootColorValue = shootColor.get_value();
    delay(5);
  }
}
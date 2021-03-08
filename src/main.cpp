#include <Arduino.h>
#include "State_machine.h"

State_machine led1(12, 1000, 1000);
State_machine led2(13, 500, 500);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  led1.Update();
  led2.Update();
}
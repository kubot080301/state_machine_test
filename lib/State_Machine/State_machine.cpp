#include "Arduino.h"
#include "State_machine.h"

void State_machine::Update(){
    unsigned long currentMillis = millis();
    
        if((led_State == HIGH) && (currentMillis - previousMillis >= OnTime)){
            previousMillis = currentMillis; 
            led_State = LOW;  
            digitalWrite(led_Pin, led_State);
        }
        else if ((led_State == LOW) && (currentMillis - previousMillis >= OffTime)){
            previousMillis = currentMillis;
            led_State = HIGH;
            digitalWrite(led_Pin, led_State);
        }    
}

State_machine::State_machine(int pin, long on, long off){
        led_Pin = pin;
        led_State = LOW;
        pinMode(led_Pin, OUTPUT);
        OnTime = on;
        OffTime = off;
        previousMillis = 0;
}
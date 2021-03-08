#ifndef KUBOT_STATE_MACHINE_H_
#define KUBOT_STATE_MACHINE_H_



class State_machine{

private:
    int led_Pin;
    int led_State;
    unsigned long previousMillis;
    long OnTime;
    long OffTime;
public:
    State_machine(int pin, long on, long off);
/*
    State_machine(void);
  ~State_machine();
*/
public:    
    void Update();
};
#endif
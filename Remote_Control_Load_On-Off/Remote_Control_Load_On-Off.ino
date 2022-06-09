#include <IRremote.h>

int Receive_PIN = 2;
IRrecv IR_Receive(Receive_PIN);
decode_results Results;

int State_1 = HIGH;
int State_2 = HIGH;
int Load_1 = 8;
int Load_2 = 9;

void setup()
  {
    IR_Receive.enableIRIn();
    pinMode(Load_1, OUTPUT);
    pinMode(Load_2, OUTPUT);  
  }

void loop() 
{
  if(IR_Receive.decode(&Results)) 
    {    
        IR_Receive.resume();
        if(Results.value == 0x58853BFC)
          {
           digitalWrite(Load_1, State_1);
           State_1 = !State_1; 
          }
        
        if(Results.value == 0x58853BCE)  
          {
           digitalWrite(Load_2, State_2);
           State_2 = !State_2; 
          }
    
    }     
}

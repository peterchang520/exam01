#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
DigitalOut Aout(D7);

float pwm;
float duty_cycle = 0;
bool add = 1; //1:duty_cycle is increasing
int count_100 = 0;

int main()
{
      uLCD.locate(2,5);
      uLCD.printf("106011102\n");
      uLCD.line(0,0,100,0,0xFFFFFF);
      uLCD.line(100,0,100,100,0xFFFFFF);
      uLCD.line(0,0,0,100,0xFFFFFF);
      uLCD.line(0,100,100,100,0xFFFFFF);

      while(1){
        Aout = 1;
        wait(0.001*duty_cycle);
        Aout = 0;
        wait(0.001-0.001*duty_cycle);

        if(duty_cycle==1){
            add = ~add;
        }
        
        if(count_100==100){
            if(add){
                duty_cycle = duty_cycle + 0.1;
            }
            else{
                duty_cycle = duty_cycle - 0.1;
            }
            count_100 = 0;
        }

        count_100++;
      }
}
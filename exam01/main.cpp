#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);

int main()
{
      uLCD.locate(2,5);
      uLCD.printf("106011102\n");
      uLCD.line(0,0,100,0,0xFFFFFF);
      uLCD.line(100,0,100,100,0xFFFFFF);
      uLCD.line(0,0,0,100,0xFFFFFF);
      uLCD.line(0,100,100,100,0xFFFFFF);
}
// ShiftRegister74HC595 - Version: Latest
#include <ShiftRegister74HC595.h>

#define DELAY_TIME 50

int numberOfShiftRegisters = 7; // number of shift registers attached in series
int serialDataPin = 0; // DS
int clockPin = 1; // SHCP
int latchPin = 2; // STCP
int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
ShiftRegister74HC595 sr (numberOfShiftRegisters, serialDataPin, clockPin, latchPin);

byte z=0;

void setup() {
  sr.setAllLow();
}

void loop() {
//   Forward_Backward();
//   Loading_Anim();
Loading2();
}



//Controller
void setXYZ(byte x, byte y, byte z)
{
  sr.setAllLow();
  delay(1);
  sr.set(x + (8 * (y - 1)), 1);
}




//Animations
void Forward_Backward()
{
  //Forward
  for (byte y=1;y<8;y++)
    if (y%2==0)
      for (byte x=1;x<8;x++)
      {
        setXYZ(x,y,z);
        delay(DELAY_TIME);
      }
    else
      for (byte x=7;x>=1;x--)
      {
        setXYZ(x,y,z);
        delay(DELAY_TIME);
      }
  
  //Backward
  for (byte y=7;y>=1;y--)
    if (y%2==0)
      for (byte x=1;x<8;x++)
      {
        setXYZ(x,y,z);
        delay(DELAY_TIME);
      }
    else
      for (byte x=7;x>=1;x--)
      {
        setXYZ(x,y,z);
        delay(DELAY_TIME);
      }
}

void Loading_Anim()
{
  for (byte a=1;a<=56;a++)
  {
    sr.set(a,1);
    delay(DELAY_TIME);
  }
  
  for (byte a=56;a>=1;a--)
  {
    sr.set(a,0);
    delay(DELAY_TIME);
  }
  
}

void Loading2()
{
    for (byte x=1;x<8;x++)
    {
        sr.setAllLow();
        sr.set(x,1);
        delay(DELAY_TIME);
    }

    for (byte x=7;x>=1;x--)
    {
        sr.setAllLow();
        sr.set(x,1);
        delay(DELAY_TIME);
    }
}
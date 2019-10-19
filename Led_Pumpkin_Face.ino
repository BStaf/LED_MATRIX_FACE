#include "LedControl.h"
#include "mouth_open.h"
#include "Mouth_Animation.h"
#include "Expression_State.h"

LedControl lc=LedControl(7,9,8,2);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=150;  // Delay between Frames

// Put values in arrays
byte eye4[] =
{
B00000000,
B00000111,
B00011111,
B01111110,
B11111100,
B01111000,
B00110000,
B00000000
};
byte eye3[] =
{
B00000000,
B00000000,
B00001111,
B01111111,
B11111100,
B01110000,
B00000000,
B00000000
};
byte eye2[] =
{
B00000000,
B00000000,
B00000000,
B00111111,
B11111000,
B00000000,
B00000000,
B00000000
};
byte eye1[] =
{
B00000000,
B00000000,
B00000000,
B00011111,
B11110000,
B00000000,
B00000000,
B00000000
};

Mouth_Animation * ma;

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  //init_mouth_open();
  ma = new Mouth_Animation(MouthOpen_Left, 7);
}


//  Take values in Arrays and Display them
void doMatirxAr(byte * matrixAr)
{
  
  for (int i = 7; i >= 0; i--)  
  {
    //lc.setRow(0,i,Right_mouth[0][i]);
    //lc.setRow(1,i,Left_mouth[0][i]);
    lc.setRow(0,i,matrixAr[i]);
    //lc.setRow(1,7-i,matrixAr[i]);
  }
}
/*void blink(int speedms){
// Put #1 frame on both Display
    doMatirxAr(eye3);
    delay(speedms);
    doMatirxAr(eye2);
    delay(speedms);
    doMatirxAr(eye1);
    delay(speedms);
    doMatirxAr(eye2);
    delay(speedms);
    doMatirxAr(eye3);
    delay(speedms);
}*/
void loop()
{
  /*
   * scan periodically
   * 
   * run animations based on scan
   * 
   */
  delay(100);
  ma->Update(lc, true);

}

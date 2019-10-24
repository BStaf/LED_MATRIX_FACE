#include "LedControl.h"
#include "mouth_open.h"
//#include "Mouth_Animation.h"
#include "Face_Animation.h"
#include "Expression_State.h"
//#include "Scene_Animation.h"

LedControl lc=LedControl(7,9,8,8);  // Pins: DIN,CLK,CS, # of Display connected


unsigned long delayTime=150;  // Delay between Frames

const byte eye1[] =
{
B11111111,
B10000001,
B10000001,
B10011001,
B10011001,
B10000001,
B10000001,
B11111111
};

const AnimationObj anObjFace[] = {
  {MouthOpen_Left,
  sizeof(MouthOpen_Left)/8,
  false}};

const AnimationObj anObjEye[] = {
  {eye1,
  1,
  false}};

Face_Animation * fa;
//Mouth_Animation * ma;
void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  lc.setIntensity(2,5);  // Set intensity levels
  lc.setIntensity(3,5);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  //init_mouth_open();
  //ma = new Mouth_Animation(MouthOpen_Left, sizeof(MouthOpen_Left)/8,false);
  fa = new Face_Animation(anObjFace, 1, anObjEye, 1, 100);
  //sa = new Scene_Animation(MouthOpen_Left, sizeof(MouthOpen_Left)/8,false);
  //ma->Init();
  fa->InitAnimation();
}


void loop()
{
  /*
   * scan periodically
   * 
   * run animations based on scan
   * 
   */
  //delay(100);
  //ma->Update(lc);
  //sa->Update(lc);
  fa->AnimationTick(lc);
}
/*
we run expressions
expression gets an annimation
animations are chained together
they need mouth and eyes
they can loop or stall
mouth has array of animation byte arrays
mouth can be stalled or looped
eyes do the same*/




  

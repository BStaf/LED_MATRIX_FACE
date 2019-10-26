#include "LedControl.h"
#include "Face_Animation.h"
#include "Expression_State.h"
#include "SCENE_Setup.h"


LedControl lc=LedControl(7,9,8,8);  // Pins: DIN,CLK,CS, # of Display connected


unsigned long delayTime=150;  // Delay between Frames

Face_Animation * fa_AwakeSleep;
Face_Animation * fa_SleepAwake;
Face_Animation * fa_AwakeJack;
Face_Animation * fa_JackAwake;
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

  fa_AwakeSleep = new Face_Animation(anObj_awakeSleep_Mouth, 2, anObj_awakeSleep_Eyes, 2, 100);
  fa_SleepAwake = new Face_Animation(anObj_sleepAwake_Mouth, 2, anObj_sleepAwake_Eyes, 2, 100);
  fa_AwakeJack = new Face_Animation(anObj_awakeJack_Mouth, 2, anObj_awakeJack_Eyes, 2, 100);
  fa_JackAwake = new Face_Animation(anObj_jackAwake_Mouth, 2, anObj_jackAwake_Eyes, 2, 100);
  fa = fa_AwakeSleep;
  fa->InitAnimation();
}
int aStep = 0;
void loop()
{
    
  if (fa->IsComplete){
    aStep++;
    if (aStep > 3)
      aStep = 0;
    switch (aStep){
      case 0:
        fa = fa_AwakeSleep;
        fa->InitAnimation();
        break;
      case 1:
        fa = fa_SleepAwake;
        fa->InitAnimation();
        break;
      case 2:
        fa = fa_AwakeJack;
        fa->InitAnimation();
        break;
      case 3:
        fa = fa_JackAwake;
        fa->InitAnimation();
        break;
    }
  }
  /*
   * scan periodically
   * 
   * run animations based on scan
   * 
   */
  fa->AnimationTick(lc);
}
/*
we run expressions
expression gets an annimation
animations are chained together
they need mouth and eyes
they can loop or stall
mouth has array of animation byte arrays
mouth can be stalled or //looped
eyes do the same*/




  

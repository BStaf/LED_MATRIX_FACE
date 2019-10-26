#include "LedControl.h"
#include "Face_Animation.h"
#include "Expression_State.h"
#include "SCENE_Setup.h"
#include "UltraSonic3Wire.h"
#include <Queue.h>


LedControl lc=LedControl(7,9,8,4);  // Pins: DIN,CLK,CS, # of Display connected
int pingPin = 6;
int pingTime = 2500; //ms

DataQueue<byte> animationQueue(4);

unsigned long delayTime=150;  // Delay between Frames

Expression_State * expState;

Face_Animation * faAwakeSleep;
Face_Animation * faSleepAwake;
Face_Animation * faAwakeJack;
Face_Animation * faJackAwake;
Face_Animation * fa;

void setup()
{
  //Serial.begin(9600);
  
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  setIntensity(0);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);

  expState = new Expression_State();
  faAwakeSleep = new Face_Animation(anObj_awakeSleep_Mouth, 2, anObj_awakeSleep_Eyes, 2, 100);
  faSleepAwake = new Face_Animation(anObj_sleepAwake_Mouth, 2, anObj_sleepAwake_Eyes, 2, 100);
  faAwakeJack = new Face_Animation(anObj_awakeJack_Mouth, 2, anObj_awakeJack_Eyes, 2, 100);
  faJackAwake = new Face_Animation(anObj_jackAwake_Mouth, 2, anObj_jackAwake_Eyes, 2, 100);
  fa = setAnimation(expState->CurrentExpression);
  fa->InitAnimation();

  //animationQueue.enqueue(expState->CurrentExpression);
  /*animationQueue.enqueue(1);
  animationQueue.enqueue(2);
  animationQueue.enqueue(3);*/
}
void setIntensity(int val){
  for (int i=0; i<4; i++)
    lc.setIntensity(i,val);
}

Face_Animation * setAnimation(byte expression){
  switch (expression){
      case EXP_AWAKE_SLEEP:
        return faAwakeSleep;
      case EXP_SLEEP_AWAKE:
        return faSleepAwake;
      case EXP_AWAKE_JACK:
        return faAwakeJack;
      case EXP_JACK_AWAKE:
        return faJackAwake;
    }
    return faAwakeJack;
}
byte lastExpState=EXP_AWAKE_SLEEP;
byte dbSavedExpState = 225; //used to require 2 successful reads 

void loop()
{
  int curInches = GetDistanceDelayed(pingPin,pingTime);

  if (lastExpState != expState->SetExpression(curInches)){
    if (dbSavedExpState == curInches){
      lastExpState = expState->CurrentExpression;
      animationQueue.enqueue(expState->CurrentExpression);
      dbSavedExpState = 225;
    }
    else
      dbSavedExpState = curInches;
  }
  
  if (!animationQueue.isEmpty()&&(fa->IsComplete)){
    fa = setAnimation(animationQueue.dequeue());
    fa->InitAnimation();
    //if in sleep mode, do less pings to save battery
    if (expState->CurrentExpression == EXP_AWAKE_SLEEP){
      pingTime = 2500;
      setIntensity(0);
    }
    else{
      pingTime = 1000;
      setIntensity(1);
    }
  }

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




  

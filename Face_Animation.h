#include "Mouth_Animation.h"

  
class Face_Animation {
  private:
    Mouth_Animation ** _mouthAnimations;
    int _mouthAnimationCnt;
    Scene_Animation ** _eyeAnimationsLeft;
    Scene_Animation ** _eyeAnimationsRight;
    int _eyeAnimationCnt;
    int _speed;
    unsigned long _lastTime;

    byte _mouthSceneStep;
    byte _eyesSceneStep;

    bool _checkTime();
    void InitScenes();
  public:
    Face_Animation(AnimationObj * MouthAnimations, int MouthAnimationCnt, AnimationObj * EyeAnimations, int EyeAnimationCnt, int Speed);
    void InitAnimation();
    void AnimationTick(LedControl lc);
};
Face_Animation::Face_Animation(AnimationObj * MouthLeftAnimations, int MouthAnimationCnt, AnimationObj * EyeAnimations, int EyeAnimationCnt, int Speed){
  _speed = Speed;
  _mouthAnimationCnt = MouthAnimationCnt;
  _eyeAnimationCnt = EyeAnimationCnt;
  
  //setup mouth animation objects
  _mouthAnimations = new Mouth_Animation*[_mouthAnimationCnt];
  for (int i=0;i< _mouthAnimationCnt;i++){
    _mouthAnimations[i] = new Mouth_Animation(MouthLeftAnimations[i].animationAr, MouthLeftAnimations[i].anSceneCnt, MouthLeftAnimations[i].isLoop);
  }
  //setup eyes
  _eyeAnimationsLeft = new Scene_Animation*[_eyeAnimationCnt];
  _eyeAnimationsRight = new Scene_Animation*[_eyeAnimationCnt];
  for (int i=0;i< _eyeAnimationCnt;i++){
    _eyeAnimationsLeft[i] = new Scene_Animation(EyeAnimations[i].animationAr, EyeAnimations[i].anSceneCnt, EyeAnimations[i].isLoop);
    _eyeAnimationsRight[i] = new Scene_Animation(EyeAnimations[i].animationAr, EyeAnimations[i].anSceneCnt, EyeAnimations[i].isLoop);
  }
}
void Face_Animation::InitAnimation(){
  _lastTime = 0;
  _mouthSceneStep = 0;
  _eyesSceneStep = 0;
  InitScenes();
}

void Face_Animation::AnimationTick(LedControl lc){ 
  //_mouthAnimations[_mouthSceneStep]->Update(lc);
  if (_checkTime()){
    if (_mouthAnimations[_mouthSceneStep]->Update(lc)){
      if (_mouthSceneStep < _mouthAnimationCnt-1){
        _mouthSceneStep++;
        _mouthAnimations[_mouthSceneStep]->Init();
      }
    }
    _eyeAnimationsLeft[_eyesSceneStep]->Update(lc);
    if (_eyeAnimationsRight[_eyesSceneStep]->Update(lc)){
      if (_eyesSceneStep < _eyeAnimationCnt-1){
        _eyesSceneStep++;
        _eyeAnimationsLeft[_eyesSceneStep]->Init(3);
        _eyeAnimationsRight[_eyesSceneStep]->Init(2);
      }
    }
  }
}
void Face_Animation::InitScenes(){
  _mouthAnimations[_mouthSceneStep]->Init();
  _eyeAnimationsLeft[_eyesSceneStep]->Init(3);
  _eyeAnimationsRight[_eyesSceneStep]->Init(2);
}
bool Face_Animation::_checkTime(){
  unsigned long curTime = millis();
  //check if time to update
  if ((curTime-_lastTime) >= _speed){
    _lastTime = curTime;
    return true;
  }
  return false;
}

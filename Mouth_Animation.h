#include "Scene_Animation.h"
#include "LedControl.h"

class Mouth_Animation {
  private:
    Scene_Animation * _rightScenes;
    Scene_Animation * _leftScenes;
    byte reverseBits(byte n);
  public:
    Mouth_Animation(byte * LeftMouthScenes, int SceneCnt, bool IsLoop);
    //byte * GetScene();
    bool Update(LedControl lc); //returns true when finished
    void Init();
    bool IsComplete;
};

Mouth_Animation::Mouth_Animation(byte * LeftMouthScenes, int SceneCnt, bool IsLoop){
  byte * p, * rightScenes;

  rightScenes = malloc(sizeof(byte) * 8 * SceneCnt);
  //right side is the reverse of the left side
  for (int i=0; i<SceneCnt * 8; i++){
      p = rightScenes + i;
      *p = reverseBits(*(LeftMouthScenes + i));
  }
  _rightScenes = new Scene_Animation(rightScenes, SceneCnt, IsLoop);
  _leftScenes = new Scene_Animation(LeftMouthScenes, SceneCnt, IsLoop);
 
}

void Mouth_Animation::Init(){
  _rightScenes->Init(0);
  _leftScenes->Init(1);
  IsComplete = false;
}

bool Mouth_Animation::Update(LedControl lc){
  if (_leftScenes->IsComplete)
    IsComplete = true;
  _rightScenes->Update(lc);
  return _leftScenes->Update(lc);
}

byte Mouth_Animation::reverseBits(byte n){ 
  byte temp=0;
  byte rev = 0;
  for (int i=0; i<8 ; i++){
    temp = n>>i & 1;
    rev |= (temp << (7-i));    
  } 
  return rev; 
} 

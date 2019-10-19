#include "LedControl.h"

class Mouth_Animation {
  private:
    byte * _rightSide;
    byte * _leftSide;
    int _sceneCnt;
    int _currentScene;

    byte reverseBits(byte n);
  public:
    Mouth_Animation(byte * LeftSide, int SceneCnt);
    byte * GetScene();
    void Update(LedControl lc, bool forward);
    
};

Mouth_Animation::Mouth_Animation(byte * LeftSide, int SceneCnt){
  byte * p;
  _sceneCnt = SceneCnt;
  _leftSide = LeftSide;
  _currentScene = 0;
  _rightSide = malloc(sizeof(byte) * 8 * SceneCnt);
  //right side is the reverse of the left side
  for (int i=0; i<SceneCnt * 8; i++){
      p = _rightSide + i;
      *p = reverseBits(*(_leftSide + i));
  }
}

void Mouth_Animation::Update(LedControl lc, bool forward){
  for (int i = 7; i >= 0; i--)  
  {
    lc.setRow(0,i,_rightSide[_currentScene*8 + i]);
    lc.setRow(1,i,_leftSide[_currentScene*8 + i]);
  }
  
  if (forward){
    if (_currentScene < _sceneCnt-1)
      _currentScene++;;
  }
  else {
    if (_currentScene > 0)
      _currentScene--;
  }
}

byte * Mouth_Animation::GetScene(){
  return _rightSide + 8;
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

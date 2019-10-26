#include "LedControl.h"

typedef struct {
  byte * animationAr;
  int anSceneCnt;
  bool isLoop;
} AnimationObj;

class Scene_Animation {
  private:
    byte * _scenes;
    int _sceneCnt;
    int _currentScene;
    bool _loop;
    byte _matrixNum;
    bool setNextScene(); //returns try if finished
  public:
    Scene_Animation(byte * Scenes, int SceneCnt, bool IsLoop);
    bool Update(LedControl lc); //returns true when finished
    void Init(byte matrixNum);
    bool IsComplete;
};

Scene_Animation::Scene_Animation(byte * Scenes, int SceneCnt, bool IsLoop){
  _loop = IsLoop;
  _sceneCnt = SceneCnt;
  _scenes = Scenes;
  _currentScene = 0;
}

void Scene_Animation::Init(byte matrixNum){
  _currentScene = 0;
  _matrixNum = matrixNum;
  IsComplete = false;
}

bool Scene_Animation::Update(LedControl lc){
  for (int i = 7; i >= 0; i--)  
  {
    lc.setRow(_matrixNum,i,_scenes[_currentScene*8 + i]);
  }
  return setNextScene();
}
bool Scene_Animation::setNextScene(){
  if (_currentScene < _sceneCnt-1)
    _currentScene++;
  else{//animation done. if looped then keep going forever
    IsComplete = true;
    if (_loop)
      _currentScene = 0;
    else // if not loop, return finished
      return true;
  }
  return false;
}

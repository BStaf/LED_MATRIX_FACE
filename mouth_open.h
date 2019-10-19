#include "led_operations.h"

//https://xantorohara.github.io/led-matrix-editor/#0000008080000000|0000804040800000|00c020101020c000|e0100808080810e0|f8040404040404f8
const byte MouthOpen_Left[] = {

  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000001,
  B00000001,
  B00000000,
  B00000000,

  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B00000010,
  B00000011,
  B00000000,
  B00000000,

  B00000000,
  B00000001,
  B00000010,
  B00000100,
  B00000100,
  B00000100,
  B00000011,
  B00000000,

  B00000000,
  B00000011,
  B00000100,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00000111,

  B00000011,
  B00000100,
  B00001000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00001111,

  B00000111,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00011111,

  B00001111,
  B00010000,
  B00100000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B00111111,

};
/*const int MouthOpen_LEN = sizeof(MouthOpen_Left)/8;
int animationIndex = 0;
//bool animateForward = true;
byte MouthOpen_Right[MouthOpen_LEN][8];

void init_mouth_open(){
  for (int i=0; i<MouthOpen_LEN; i++){
    for (int j=0; j<8 ; j++){
      MouthOpen_Right[i][j] = reverseBits(MouthOpen_Left[i][j]);
    }
  }
}

void showNextSceen(LedControl lc, bool open){
  for (int i = 7; i >= 0; i--){
    lc.setRow(0,i,MouthOpen_Right[animationIndex][i]);
    lc.setRow(1,i,MouthOpen_Left[animationIndex][i]);
  }
  if (open){
    if (animationIndex < MouthOpen_LEN-1){
      animationIndex++;
    }
    else
      animationIndex--;
  }
}*/

/*
 https://xantorohara.github.io/led-matrix-editor/#0078c40279c90d03
 
 const uint64_t IMAGES[] = {
  0x0078c40279c90d03
};
const int IMAGES_LEN = sizeof(IMAGES)/8;

  */
/*
byte Left_mouth[][8] = {
{
  B11000000,
  B10110000,
  B10010011,
  B10011110,
  B01000000,
  B00100011,
  B00011110,
  B00000000
}};
const int Mouth_open_len = sizeof(Left_mouth)/8;

byte Right_mouth[Mouth_open_len][8];


byte reverseBits(byte n) 
{ 
  byte temp=0;
  byte rev = 0;
  for (int i=0; i<8 ; i++){
    temp = n>>i & 1;
    rev |= (temp << (7-i));    
  } 
  return rev; 
} 
void init_mouth_open(){
  for (int i=0; i<Mouth_open_len; i++){
    for (int j=0; j<8 ; j++){
      Right_mouth[i][j] = reverseBits(Left_mouth[i][j]);
    }
  }
}*/

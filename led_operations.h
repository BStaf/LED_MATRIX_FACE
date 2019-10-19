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

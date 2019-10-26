/**************************************************
 * Handles what expression to use from the 
 * distance detected
 * Defines all expressions
 **************************************************/

//expression definitions
#define STATE_SLEEPING    0
#define STATE_AWAKE       1
#define STATE_JACK        2

#define EXP_AWAKE_SLEEP   0
#define EXP_SLEEP_AWAKE   1
#define EXP_AWAKE_JACK    3 
#define EXP_JACK_AWAKE    2

const byte expressionDisanceAr[] = {
  30,  //sleeping
  15, //awake
  0 //jack
};

class Expression_State{
  private:
    byte _getExpressionWithDistance(int distance);
  public:
    //current expression 
    byte CurrentExpression;
    Expression_State();
    //sets and returns CurrentExpression
    byte SetExpression(int distance);
};

Expression_State::Expression_State(){
  CurrentExpression = EXP_AWAKE_SLEEP;
}

byte Expression_State::SetExpression(int distance){
  CurrentExpression = _getExpressionWithDistance(distance);
  return CurrentExpression;
}

byte Expression_State::_getExpressionWithDistance(int distance){
  for (int i=0; i<3/*sizeof(expressionDisanceAr)*/; i++){
    if (distance >= expressionDisanceAr[i])
      switch (i){
        case STATE_SLEEPING:
          return EXP_AWAKE_SLEEP;
        case STATE_AWAKE:
          if ((CurrentExpression == EXP_AWAKE_JACK)||(CurrentExpression == EXP_JACK_AWAKE))
            return EXP_JACK_AWAKE;
          return EXP_SLEEP_AWAKE;
        case STATE_JACK:
          return EXP_AWAKE_JACK;
      }
  }
     
  //return EXP_AWAKE_SLEEP;
  //return EXP_SLEEP_AWAKE;
  //return EXP_AWAKE_JACK;
}

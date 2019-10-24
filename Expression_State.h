/**************************************************
 * Handles what expression to use from the 
 * distance detected
 * Defines all expressions
 **************************************************/

//expression definitions
#define EXP_SLEEPING    3
#define EXP_AWAKE       2
#define EXP_SURPPRISED  1
#define EXP_ANGRY       0

const byte expressionDisanceAr[] = {
  5,  //EXP_ANGRZY
  10, //EXP_SURPRISED
  15, //EXP_AWAKE
  20, //EXP_SLEEPING0
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
  CurrentExpression = EXP_SLEEPING;
}

byte Expression_State::SetExpression(int distance){
  CurrentExpression = _getExpressionWithDistance(distance);
  return CurrentExpression;
}

byte Expression_State::_getExpressionWithDistance(int distance){
  for (int i=sizeof(expressionDisanceAr);i>=0;i--){
    if (distance >= expressionDisanceAr[i])
      return i; 
  }   
}

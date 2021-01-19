#ifndef POSITION_H
#define POSITION_H

#include "style.h"

class Position: public Style{
public:
  Position(int top = 0, int left = 0){
      _top = std::to_string(top);
      _left = std::to_string(left);
  }
  
  std::string renderStyle() const override{
      return t_1 + _top + t_2 + _left + end;
  }

private:
  std::string _top;
  std::string _left;
  std::string t_1 = "top:";
  std::string t_2 = "px;left:";
  std::string end = "px;position:absolute;";
};

#endif
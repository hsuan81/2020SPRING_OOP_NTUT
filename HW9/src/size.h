#ifndef SIZE_H
#define SIZE_H

#include "style.h"

class Size: public Style{
public:
  Size(int height = 0, int weight = 0){
      _height = std::to_string(height);
      _weight = std::to_string(weight);
  }
  
  std::string renderStyle() const override{
      return t_1 + _height + t_2 + _weight + end;
  }

private:
  std::string _height;
  std::string _weight;
  std::string t_1 = "height:";
  std::string t_2 = "px;weight:";
  std::string end = "px;";
};

#endif
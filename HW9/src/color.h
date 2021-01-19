#ifndef COLOR_H
#define COLOR_H

#include "style.h"

class Color: public Style{
public:
  Color(std::string color = "#000000"){
      _color = color;
  }
  
  std::string renderStyle() const override{
      return begin + _color + end;
  }

private:
  std::string _color;
  std::string begin = "color:";
  std::string end = ";";
};

#endif
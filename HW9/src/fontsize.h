#ifndef FONTSIZE_H
#define FONTSIZE_H

#include "style.h"

class FontSize: public Style{
public:
  FontSize(int fsize = 16){
      _fsize = std::to_string(fsize);
  }
  
  std::string renderStyle() const override{
      return begin + _fsize + end;
  }

private:
  std::string _fsize;
  std::string begin = "font-size:";
  std::string end = "px;";
};

#endif
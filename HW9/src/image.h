#ifndef IMAGE_H
#define IMAGE_H

#include "tag.h"
#include "position.h"
#include "size.h"
#include "style.h"

#include<vector>

class Image : public Tag{
public:
  Image(std::string id = ""): Tag(id), imageSrc(""){
  }
  
  std::string render() const override{
    std::string id = this->getId();
    std::string add_style;
    for (Style * s: styles){
      add_style = add_style + s->renderStyle();
    }
    return "<img id='" + id + "' src='"+ imageSrc +"' style='" + add_style + "'/>";
  }


  void setSrc(std::string imageSrc){
    this->imageSrc=imageSrc;
  }

private:
  std::string imageSrc;
};

#endif
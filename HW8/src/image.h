#ifndef IMAGE_H
#define IMAGE_H

#include "tag.h"

class Image : public Tag{
public:
  Image(): Tag(), imageSrc(""), top("0px"), left("0px"){
  }
  
  Image(std::string id): Tag(id){
    imageSrc = "";
    top = "0px";
    left = "0px";
  }
  
  std::string render() const override{
    std::string id = this->getId();
    return "<img id='" + id + "' src='"+ imageSrc +"' style='top:" + top + ";left:" + left + ";position:absolute;'/>";
  }

  void setPosition(std::string top, std::string left) override{
    this->top=top;
    this->left=left;
  }

  void setSrc(std::string imageSrc) override{
    this->imageSrc=imageSrc;
  }

private:
  std::string imageSrc;
  std::string top;
  std::string left;
};

#endif
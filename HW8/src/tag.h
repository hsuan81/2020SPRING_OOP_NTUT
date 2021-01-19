#ifndef TAG_H
#define TAG_H

#include <cstring>

class Tag{
public:
  virtual std::string render() const = 0;

  virtual void setColor(std::string color){}

  virtual void setFontSize(std::string fontSize){}

  virtual void setText(std::string content){}

  virtual void setPosition(std::string top, std::string left){}

  virtual void setSrc(std::string imageSrc){}


  Tag():_id(""){
  }

  Tag(std::string id){
      _id = id;
  }

  std::string getId() const{
      return _id;
  }

private:
  std::string _id; // the variable must be set to private

};

#endif

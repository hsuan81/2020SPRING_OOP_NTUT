#ifndef TEXT_H
#define TEXT_H

#include "tag.h"


class Text : public Tag{
public:
  Text(): Tag(), content(""), color("#000000"), fontSize("16px"){
  };

  Text(std::string id): Tag(id){
      content = "";
      color = "#000000";
      fontSize = "16px";
  }

  std::string render() const override{
      std::string ID = this->getId();
      return "<p id='" + ID + "' style='color:" + color + ";font-size:" + fontSize + ";'>" + content + "</p>";
  }

  void setColor(std::string color) override{
      this->color = color;
  }

  void setFontSize(std::string fontSize) override{
      this->fontSize = fontSize;
  }

  void setText(std::string content) override{
      this->content = content;
  }

private:
  std::string content;
  std::string color;
  std::string fontSize;
};

#endif

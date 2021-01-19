#ifndef TEXT_H
#define TEXT_H

#include "tag.h"
#include "color.h"
#include "fontsize.h"
#include "style.h"

#include<vector>


class Text : public Tag{
public:
  Text(std::string id = ""): Tag(id), content(""){
  }

  void setText(std::string content){
      this->content = content;
  }

  std::string render() const override{
      std::string ID = this->getId();
      std::string add_style;
      for (Style * s: styles){
        add_style = add_style + s->renderStyle();
      }
      return "<p id='" + ID + "' style='" + add_style + "'>" + content + "</p>";
  }


private:
  std::string content;
};

#endif

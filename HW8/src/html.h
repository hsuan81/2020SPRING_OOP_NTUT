#ifndef HTML_H
#define HTML_H

#include "text.h"
#include "image.h"

#include "tag.h"

#include<fstream>
#include<cstring>
#include<vector>


class Html{
public:
  void appendTag(Tag *child){
    tags.push_back(child);
  }

  std::string render(){
    std::string result = html_head;
    for (Tag * t : tags){
      result += t->render();
    }  
    return result + html_end;
  }

  void outputHtml(){
     std::ofstream file;
     file.open("main.html");
     file<<this->render();
     file.close();
  }

private:
  std::vector<Tag*> tags;
  const std::string html_head="<HTML><body>";
  const std::string html_end="</body></HTML>";
};

#endif

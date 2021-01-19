#ifndef HTML_H
#define HTML_H

#include "text.h"

#include<fstream>
#include<cstring>
#include<vector>

class Html{
public:
  void appendChild(Text child){
      tags.push_back(child);
  }

  int size(){
      return tags.size();
  }

  std::string render(){
      std::string result = html_head;
      Text t;

      if (!tags.empty()){
          for (int i = 0; i<tags.size(); i ++){
              result = result + tags[i].render();
          }
      }
      result = result + html_end;
      return result;
  }

  void outputHtml(){
     std::ofstream file;
     file.open("main.html");
     file<<this->render();
     file.close();
  }

private:
  std::vector<Text> tags;
  const std::string html_head="<HTML><body>";
  const std::string html_end="</body></HTML>";
};

#endif

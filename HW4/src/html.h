#ifndef HTML_H
#define HTML_H

#include "text.h"
#include "image.h"

#include<fstream>
#include<cstring>
#include<vector>

class Html{
public:
  void appendText(Text child){
      texts.push_back(child);
  }

  void appendImage(Image child){
      images.push_back(child);
  }
  //int size(){
//       return tags.size();
//   }

  std::string render(){
      std::string result = html_head;
      for(Image i : images){
          result = result + i.render();
      }
      for (Text t : texts){
            result = result + t.render();
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
  std::vector<Text> texts;
  std::vector<Image> images;
  const std::string html_head="<HTML><body>";
  const std::string html_end="</body></HTML>";
};

#endif

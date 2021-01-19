#ifndef TEXT_H
#define TEXT_H

class Text{
public:
  Text(){
      content = "";
  };
  Text(std::string t){
      content = t;
  }

  std::string render(){

      if (content.empty()){
          content = "<p></p>";
          return content;
          }
      else{
          content = "<p>" + content + "</p>";
          return content;
          }
  }

  void setText(std::string add_content){
      content = content.append(add_content);
  }

private:
  std::string content;
};

#endif

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
      return "<p style='color:" + color + ";font-size:" + fontSize + ";'>" + content + "</p>";
  }

  void setColor(std::string color){
      this->color = color;
  }

  void setFontSize(std::string fontSize){
      this->fontSize = fontSize;
  }

  void setText(std::string content){
      this->content = content;
  }

private:
  std::string content;
  std::string color = "#000000";
  std::string fontSize = "16px";
};

#endif

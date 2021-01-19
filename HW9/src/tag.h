#ifndef TAG_H
#define TAG_H

#include <vector>
#include <cstring>
#include "style.h"

class Tag{
public:
  virtual std::string render() const = 0;

  


  Tag(std::string id = ""):_id(id){
  }
  
  void addStyle(Style * style){
    styles.push_back(style);
  }
  
  std::string getId() const{
      return _id;
  }

protected:
  std::vector<Style *> styles;

private:
  std::string _id; // the variable must be set to private

};

#endif

# OOP HW8
For this assignment, please put base class Tag in src/tag.h. Test class Image in test/ut_image.h, test class text in test/ut_text.h. You will have 3 output files: bin/ut_all for all testing, bin/ui_main for ui executable and main.html is your ui output product

## Purpose of this assignment

Constructing UI framework from the scratch by using html
  
## Problems


In homework 4, we implement the basic <p> and <img> without inheritance, in consequence, your program must to specify the output order. In this assignment, we implement these two class in polymorphic way to free the output order of html.

Please implement or modify these class and methods:

-   class Html
-   class Text
-   class Image
-   class Tag
-   Tag.Tag()
-   Tag.Tag(std::string id)
-   Tag.getId()
-   Html.appendTag(Tag *child)
-   Html.render()
-   Text.Text()
-   Text.Text(std::string id)
-   Text.render()
-   Text.setColor(std::string color)
-   Text.setFontSize(std::string fontSize)
-   Text.setText(std::strgin content)
-   Image.Image()
-   Image.Image(std::string id)
-   Image.render()
-   Image.setSrc(std::string imageSrc)
-   Image.setPosition(std::string top, std::string left)

## Design concept:

This UI framework is capable of adding multiple child tag (i.e. text, image) to the body of html, and output with proper html tag format. The following is an example:

main.cpp

```
#include<iostream>

#include "./html.h"
#include "./text.h"
#include "./image.h"

int main(){
  Html h;
  Text t1;
  Text t2;
  Image i;
  t1.setText("Hello, World");
  t1.setColor("#FF0800");
  t2.setText("This is a Hash Browns :D");
  t2.setFontSize("32px");
  i.setSrc("Hash Browns.png");
  i.setPosition("200px","0px");
  h.appendTag(&t1);
  h.appendTag(&t2);
  h.appendTag(&i);
  h.outputHtml();
  std::cout << "output successful" << std::endl;
  return 0;
}
```

main.html (輸出成一行即可，這邊換行是幫助閱讀)

```
<HTML>
  <body>
    <p id='' style='color:#FF0800;font-size:16px;'>Hello, World</p>
    <p id='' style='color:#000000;font-size:32px;'>This is a Hash Browns :D</p>
    <img id='' src='Hash Browns.png' style='top:200px;left:0px;position:absolute;'/>
  </body>
</HTML>
```

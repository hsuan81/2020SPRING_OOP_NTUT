# OOP HW4
For this assignment, please put class Image in src/image.h. Test class Image in test/ut_image.h, test class text in test/ut_text.h. You will have 3 output files: bin/ut_all for all testing, bin/ui_main for ui exectuable and main.html is your ui output product

## Purpose of this assignment

constructing UI framework from the scratch by using html
  
## Problems


In previous homework, we implement the basic < html > and < p > tag. In this assignment, we continue with new < img > tag and add style in it!

Please implement or modify these class and methods:

-   class Html
-   class Text
-   class Image
-   Html.appendText(Text child) //modify from appendChild
-   Html.appendImage(Image child)
-   Html.render()
-   Text.render()
-   Text.setColor(std::string color)
-   Text.setFontSize(std::string fontSize)
-   Image.render()
-   Image.setSrc(std::string imageSrc)
-   Image.setPosition(std::string top, std::string left)

## Design concept
This UI framework is capable with adding multiple child tag (ie. text, image) to the body html, and output **all image child first** then **all text child** in string with proper html tag formate. The following is an example.

main.cpp

```
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
  h.appendText(t1);
  h.appendText(t2);
  h.appendImage(i);
  h.outputHtml();
  std::cout << "output successful" << std::endl;
  return 0;
}
```
main.html (輸出成一行即可， 這邊換行是幫助閱讀)

```
<HTML>
	<body>
		<img src='Hash Browns.png' style='top:200px;left:0px;position:absolute;'/>
		<p style='color:#FF0800;font-size:16px;'>Hello, World</p>
		<p style='color:#000000;font-size:32px;'>This is a Hash Browns :D</p>
	</body>
</HTML>
```

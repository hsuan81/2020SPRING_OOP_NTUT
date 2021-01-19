# OOP HW3
For this assignment, please put class html in src/html.h, class text in src/text.h. Test class html in test/ut_html.h, test class text in test/ut_text.h. You will have 3 output files: bin/ut_all for all testing, bin/ui_main for ui exectuable and main.html is your ui output product

## Purpose of this assignment

Constructing UI framework from the scratch by using html
  
## Problems

There are many UI framework like QT or .NET now a day. From this assignment, we want you to develop an UI framework using html by your self. Let's start from the most basic tags, < html > and < p >, and test it.

Please implement these class and methods:

-   class Html
-   class Text
-   Html.appendChild(Text child)
-   Html.render()
-   Html.outputHtml()
-   Text.render()
-   Text.setText(std::string content)

## Design concept
This UI framework is capable with adding multiple child tag (ie. text) to the body html, and output all child in string with proper html tag formate. The following is an example.

main.cpp

```
int main(){
  Html h; <-main body tag
  Text t1;
  Text t2; <-two <p> tag
  t1.setText("Hello, World"); <-first tag with "Hello, World" content
  t2.setText("This is a simple ui output"); <-second tag with "This is a simple ui output" content
  h.appendChild(t1);
  h.appendChild(t2); <-put two children into body
  h.outputHtml(); <-output content to main.html
  return 0;
}
```

main.html (輸出成一行即可， 這邊換行是幫助閱讀)

```
<HTML> //<- <html>, <body> render by class html
	<body>
		<p>Hello, World</p> //<-first tag
		<p>This is a simple ui output</p> //<-second tag
	</body>
</HTML>
```

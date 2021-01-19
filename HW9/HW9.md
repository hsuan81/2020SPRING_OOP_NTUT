﻿
# OOP HW9
To improve your ability to read and understand codes written by others, for this assignment, you must complete all the production code without any provided code template, including `./src/color.h`, `./src/fontsize.h`, `./src/position.h`, `./src/size.h`, and `./src/style.h`. In addition, we will provide all the TA tests and you DON'T need write any unit test yourself

**You will have 3 output files:**

1.  bin/ut_all for all testing
2.  bin/ui_main for ui executable
3.  main.html is your ui output file

## Purpose of this assignment

Learn how to do reverse engineering with finished test.
  
## Problems



In homework 8, we implement <p> and <img> with inheritance. In this assignment, we split all styles into different classes, making them inherit the class `Style` in polymorphic way as well. Moreover, you need to design class interface yourself by investigate test we provide, any design that pass the test are accepted. However, please make your class interface as small as possable and ease to extend. Don't just output string that we want or you will get 0 point.

Please complete or modify these class:

-   class Color
-   class Fontsize
-   class Position
-   class Size
-   class Style
-   class Image
-   class Text
-   class Tag
-   class Html

## Design concept:

Each `Tag` object is capable of adding different style (e.g. color, size), and output with proper html tag format.

#include "../src/text.h"

TEST(Text, SetText){
    Text a;
    std::string s = "hello";

    a.setText(s);

    ASSERT_EQ(std::string("<p style='color:#000000;font-size:16px;'>hello</p>"), a.render());
}

TEST(Text, Color){
    Text t;
    std::string color ("#123000");
    t.setColor(color);
    ASSERT_EQ(std::string("<p style='color:#123000;font-size:16px;'></p>"), t.render());
}

TEST(Text, Font){
    Text t;
    std::string font("14px");
    t.setFontSize(font);
    ASSERT_EQ(std::string("<p style='color:#000000;font-size:14px;'></p>"), t.render());
}

TEST(Text, nosetRender){
    Text _set;

    ASSERT_EQ(std::string("<p style='color:#000000;font-size:16px;'></p>"), _set.render());
}

TEST(Text, setRender){
    Text t;
    t.setColor("#100000");
    t.setFontSize("10px");
    ASSERT_EQ(std::string("<p style='color:#100000;font-size:10px;'></p>"), t.render());
}

TEST(Text, allRender){
    Text t;
    t.setText("hello");
    t.setColor("#100000");
    t.setFontSize("14px");
    ASSERT_EQ(std::string("<p style='color:#100000;font-size:14px;'>hello</p>"), t.render());
}
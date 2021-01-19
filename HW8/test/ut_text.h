#include "../src/text.h"

TEST(TextTest, DefaultConstructor){
    Tag * t = new Text();
    ASSERT_TRUE(t->getId().empty());
    ASSERT_EQ(std::string("<p id='' style='color:#000000;font-size:16px;'></p>"), t->render());
}

TEST(TextTest, Constructor){
    Tag * t = new Text("id");
    EXPECT_EQ(std::string("id"), t->getId());
    ASSERT_EQ(std::string("<p id='id' style='color:#000000;font-size:16px;'></p>"), t->render());
}

TEST(TextTest, NoSetRender){
    Tag * t = new Text(std::string("empty"));
    ASSERT_EQ(std::string("<p id='empty' style='color:#000000;font-size:16px;'></p>"), t->render());
}

TEST(TextTest, Render){
    Tag * t = new Text(std::string("test"));
    t->setText("hello");
    t->setFontSize("15px");
    ASSERT_EQ(std::string("<p id='test' style='color:#000000;font-size:15px;'>hello</p>"), t->render());
}

TEST(TextTest, SetText){
    Tag * t = new Text();
    std::string s = "hello";
    t->setText(s);
    ASSERT_EQ(std::string("<p id='' style='color:#000000;font-size:16px;'>hello</p>"), t->render());
}

TEST(TextTest, Color){
    Tag * t = new Text();
    std::string color ("#123000");
    t->setColor(color);
    ASSERT_EQ(std::string("<p id='' style='color:#123000;font-size:16px;'></p>"), t->render());
}

TEST(TextTest, Font){
    Tag * t = new Text();
    std::string font("14px");
    t->setFontSize(font);
    ASSERT_EQ(std::string("<p id='' style='color:#000000;font-size:14px;'></p>"), t->render());
}

TEST(TextTest, SetTextWithId){
    Tag * t = new Text(std::string("id"));
    std::string s = "hello";
    t->setText(s);
    ASSERT_EQ(std::string("<p id='id' style='color:#000000;font-size:16px;'>hello</p>"), t->render());
}

TEST(TextTest, ColorWithId){
    Tag * t = new Text(std::string("id"));
    std::string color ("#123000");
    t->setColor(color);
    ASSERT_EQ(std::string("<p id='id' style='color:#123000;font-size:16px;'></p>"), t->render());
}

TEST(TextTest, FontWithId){
    Tag * t = new Text(std::string("id"));
    std::string font("14px");
    t->setFontSize(font);
    ASSERT_EQ(std::string("<p id='id' style='color:#000000;font-size:14px;'></p>"), t->render());
}

TEST(Text, allRender){
    Text t;
    t.setText("hello");
    t.setColor("#100000");
    t.setFontSize("14px");
    ASSERT_EQ(std::string("<p id='' style='color:#100000;font-size:14px;'>hello</p>"), t.render());
}


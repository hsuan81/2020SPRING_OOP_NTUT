#include "../src/image.h"

TEST(ImageTest, DefaultConstructor){
    
    Tag * t = new Image();
    ASSERT_TRUE(t->getId().empty());
    ASSERT_EQ(std::string("<img id='' src='' style='top:0px;left:0px;position:absolute;'/>"), t->render());
}

TEST(ImageTest, Constructor){
    Tag * t = new Image("id");
    EXPECT_EQ(std::string("id"), t->getId());
    ASSERT_EQ(std::string("<img id='id' src='' style='top:0px;left:0px;position:absolute;'/>"), t->render());
}

TEST(ImageTest, NoSetRender){
    Tag * t = new Image("empty");
    ASSERT_EQ(std::string("<img id='empty' src='' style='top:0px;left:0px;position:absolute;'/>"), t->render());
}

TEST(ImageTest, Render){
    Tag * t = new Image(std::string("test"));
    t->setPosition("200px", "10px");
    ASSERT_EQ(std::string("<img id='test' src='' style='top:200px;left:10px;position:absolute;'/>"), t->render());
}

TEST(ImageTest, Position){
    Tag * t = new Image(std::string("test"));
    t->setPosition("100px", "10px");
    ASSERT_EQ(std::string("<img id='test' src='' style='top:100px;left:10px;position:absolute;'/>"), t->render());
}

TEST(ImageTest, Source){
    Tag * t = new Image(std::string("test"));
    t->setSrc("source");
    ASSERT_EQ(std::string("<img id='test' src='source' style='top:0px;left:0px;position:absolute;'/>"), t->render());
}

TEST(IMAGE, allSet){
    Tag * t = new Image(std::string("test"));
    t->setSrc("source");
    t->setPosition("200px", "10px");
    ASSERT_EQ("<img id='test' src='source' style='top:200px;left:10px;position:absolute;'/>",t->render());
}

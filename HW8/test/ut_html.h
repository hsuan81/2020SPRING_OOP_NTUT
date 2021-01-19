#include "../src/html.h"
#include "../src/text.h"
#include "../src/image.h"

TEST(HtmlTest, AppendTag){
    Tag * t = new Text();
    Html h;
    h.appendTag(t);
    ASSERT_EQ("<HTML><body><p id='' style='color:#000000;font-size:16px;'></p></body></HTML>", h.render());
}

TEST(HtmlTest, AddImage){
    Tag * t = new Image();
    Html h;
    h.appendTag(t);
    ASSERT_EQ("<HTML><body><img id='' src='' style='top:0px;left:0px;position:absolute;'/></body></HTML>", h.render());
}

TEST(HtmlTest, Render){
    Html h;
    ASSERT_EQ("<HTML><body></body></HTML>", h.render());
}

TEST(HtmlTest, AddMultiple){
    Html h;
    Text t1;
    Text t2;
    Image i1;
    Image i2;
    t1.setText("test1");
    t2.setText("test2");
    i1.setSrc("Hash Browns.png");
    i2.setSrc("Hash Browns.png");
    h.appendTag(&t1);
    h.appendTag(&t2);
    h.appendTag(&i1);
    h.appendTag(&i2);

    ASSERT_EQ(std::string("<HTML><body><p id='' style='color:#000000;font-size:16px;'>test1</p><p id='' style='color:#000000;font-size:16px;'>test2</p><img id='' src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/><img id='' src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/></body></HTML>"), h.render());
}

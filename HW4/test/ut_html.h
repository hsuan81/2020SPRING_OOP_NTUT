#include "../src/html.h"
#include "../src/text.h"
#include "../src/image.h"

TEST(Html, AddText){
    Text t;
    Html h;
    t.setText("rendertest");
    h.appendText(t);
    ASSERT_EQ(std::string("<HTML><body><p style='color:#000000;font-size:16px;'>rendertest</p></body></HTML>"), h.render());
}

TEST(Html, AddImage){
    Html h;
    Image i;
    h.appendImage(i);
    ASSERT_EQ(std::string("<HTML><body><img src='' style='top:0px;left:0px;position:absolute;'/></body></HTML>"), h.render());
}

TEST(Html, Render){
    Html h;
    ASSERT_EQ(std::string("<HTML><body></body></HTML>"), h.render());
}

TEST(Html, AddMultiple){
    Html h;
    Text t1;
    Text t2;
    Image i1;
    Image i2;
    t1.setText("test1");
    t2.setText("test2");
    i1.setSrc("Hash Browns.png");
    i2.setSrc("Hash Browns.png");
    h.appendText(t1);
    h.appendText(t2);
    h.appendImage(i1);
    h.appendImage(i2);

    ASSERT_EQ(std::string("<HTML><body><img src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/><img src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/><p style='color:#000000;font-size:16px;'>test1</p><p style='color:#000000;font-size:16px;'>test2</p></body></HTML>"), h.render());
}






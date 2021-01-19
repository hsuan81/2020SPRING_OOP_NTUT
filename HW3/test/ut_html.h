#include "../src/html.h"
#include "../src/text.h"

TEST(Html, Addchild){
    Text t("a");
    Html h;

    EXPECT_EQ(0, h.size());
    h.appendChild(t);
    ASSERT_EQ(1, h.size());
}
TEST(Html, Render){
    Text t("a");
    Html h;
    std::string result;

    h.appendChild(t);
    result = h.render();

    ASSERT_EQ(std::string("<HTML><body><p>a</p></body></HTML>"), result);
}

TEST(Html, Emptybody){
    Html h;
    std::string result;

    result = h.render();

    ASSERT_EQ(std::string("<HTML><body></body></HTML>"), result);
}

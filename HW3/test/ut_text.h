#include "../src/text.h"

TEST(Text, Addtag){
    Text _content ("Addtag");

    ASSERT_EQ(std::string("<p>Addtag</p>"), _content.render());
    
}

TEST(Text, NotSet){
    Text _set;

    ASSERT_EQ(std::string("<p></p>"), _set.render());

}

TEST(Text, Set){
    Text a;
    std::string s = "hello";

    a.setText(s);

    ASSERT_EQ(std::string("<p>hello</p>"), a.render());
}



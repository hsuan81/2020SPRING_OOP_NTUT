#include "../src/image.h"

// Image.render()
// - return the imageSrc with proper < img > tag pair with default style.(10%)
// - return the empty < img > tag if imageSrc not set with default style.(10%)

// Image.setSrc(std::string imageSrc)
// - set the image source of the image.(5%)

// Image.setPosition(std::string top, std::string left)
// - set the position of the image.(5%)

TEST(IMAGE,render){
	Image i;
	ASSERT_EQ("<img src='' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, setSrc){
    Image i;
    i.setSrc("source");
    ASSERT_EQ("<img src='source' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, setPosition){
    Image i;
    i.setPosition("200px", "10px");
    ASSERT_EQ("<img src='' style='top:200px;left:10px;position:absolute;'/>",i.render());
}

TEST(IMAGE, allSet){
    Image i;
    i.setSrc("source");
    i.setPosition("200px", "10px");
    ASSERT_EQ("<img src='source' style='top:200px;left:10px;position:absolute;'/>",i.render());
}
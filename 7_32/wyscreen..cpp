/*#include"Screen.h"
 Screen& Screen::move (const pos r,const pos c)
{
	pos row=r*width;
	cursor=row+c;
	return *this;

}
 Screen& Screen::set (char c)
{
	contents[cursor] =c;
	return *this;
}	
 Screen& Screen::set(pos r,pos col,char ch)
{
	contents[r*width+col]=ch;
	return *this;
}

#include "wyscreen.h"

inline wyScreen &wyScreen::move(const pos r, const pos c)
{
    cursor = r * width + c;
    return *this;
}

inline wyScreen &wyScreen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline wyScreen &wyScreen::set(wyScreen::pos r, wyScreen::pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

void wyScreen_mgr::clear(ScreenIndex i)
{
    wyScreen &s = this->wyScreens[i];
    s.contents = std::string(" ", s.height * s.width);
}
*/
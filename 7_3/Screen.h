#ifndef SCREEN_H
#define SCREEN_H
#include<string>
class wyScreen
{
public:
    typedef std::string::size_type pos;

    //!  constructs:
    wyScreen() = default;
    wyScreen(const pos h, const pos w) : height(h), width(w), contents(" ", h * w) {  }
    wyScreen(const pos h, const pos w, char c) : height(h), width(w), contents(h * w, c){  }

   inline wyScreen &move(const pos r, const pos c);
    inline wyScreen &set(char c);
   inline wyScreen &set(pos r, pos col, char ch);

    wyScreen &display(std::ostream &os)
    {do_display(os);    return *this;}
    const wyScreen &display(std::ostream &os) const
    {do_display(os);    return *this;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents;}
};

	
#endif
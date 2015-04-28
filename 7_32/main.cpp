#include <iostream>
#include <string>
#include <vector>
#include"wyscreen.h"
int main()
{
  wyScreen screen(5,3,'x');
  screen.move(4,0).set('#').display(std::cout);
  	std::cout<<'\t';
	return 0;
}

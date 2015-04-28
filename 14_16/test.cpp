/*
编写程序，逐行读入一个输入文件，将内容存入到一个
Strblob中，用一个StrBlobPtr打印出StrBlob中的元素
*/
#include"My_14_16.h"
#include<fstream>
#include<iostream>
int main()
{
  std::ifstream ifs("book.txt");
  std::ifstream rhs("title.txt");
  StrBlob blob1;
  StrBlob blob2;

  for (std::string str; std::getline(ifs, str); )
       blob1.push_back(str);

  for (std::string str; std::getline(rhs, str); )
       blob2.push_back(str);

  StrBlobPtr pbeg1(blob1.begin()), pend1(blob1.end());
  std::cout<<"blob1 is "<<std::endl;
  for (; pbeg1 != pend1; pbeg1.incr())
  std::cout << pbeg1.deref() << std::endl;

  std::cout<<std::endl;
  
  std::cout<<"blob2 is "<<std::endl;
  StrBlobPtr pbeg2(blob2.begin()), pend2(blob2.end());

  for (; pbeg2 != pend2; pbeg2.incr())
     std::cout << pbeg2.deref() << std::endl;

  std::cout<<std::endl;
  
  std::cout<<"blob1==blob2?"<<std::endl;
  if(blob1==blob2)
   {
    std::cout<<"Yes"<<std::endl;
   }
  else
    std::cout<<"No"<<std::endl;

  std::cout<<"blob1<blob2?"<<std::endl;
  if(blob1<blob2)
   {
   	std::cout<<"Yes"<<std::endl;
   }
  else
   	std::cout<<"No"<<std::endl;



   
  std::cout<<"pbeg1==pbeg2?"<<std::endl;
  if(pbeg1==pbeg2)
   {
   	std::cout<<"Yes"<<std::endl;
   }
  else
   	std::cout<<"No"<<std::endl;

  std::cout<<std::endl;
  for (int i = 0; i != blob1.size(); ++i)
  {
    std::cout<<"blob1["<<i+1<<"]:"<<blob1[i]<<std::endl;
  }
  std::cout<<std::endl;
  std::cout<<std::endl;
  for (int i = 0; i != blob2.size(); ++i)
  {
    std::cout<<"blob2["<<i+1<<"]:"<<blob2[i]<<std::endl;
  }
  std::cout<<"--------------"<<std::endl;
}

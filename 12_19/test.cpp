/*
编写程序，逐行读入一个输入文件，将内容存入到一个
Strblob中，用一个StrBlobPtr打印出StrBlob中的元素
*/
#include"My_12_19.h"
#include<fstream>
#include<iostream>
int main()
{
  std::ifstream ifs("book.txt");
  StrBlob blob;
  for (std::string str; std::getline(ifs, str); )
       blob.push_back(str);
  for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
       std::cout << pbeg.deref() << std::endl;
}

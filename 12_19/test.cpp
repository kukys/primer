/*
��д�������ж���һ�������ļ��������ݴ��뵽һ��
Strblob�У���һ��StrBlobPtr��ӡ��StrBlob�е�Ԫ��
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
#include<iostream>
#include<iterator>
#include<fstream>
int main()
{
  std::ifstream ifs("number.txt");
  std::ofstream foutput1("jishu.txt");
  std::ofstream foutput2("oushu.txt");
  std::istream_iterator<int> num_iter(ifs),eof;
  std::ostream_iterator<int> out_iter1(foutput1," ");
  std::ostream_iterator<int> out_iter2(foutput2,"\n");
  while(num_iter!=eof)
  {
    if(*num_iter%2!=0)
      {
        out_iter1=*num_iter;
      }
    else
      {
        out_iter2=*num_iter;
      }
      *num_iter++;
  }
}
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using std::vector;
using std::ifstream;
using std::string;
 using std::getline;
  using std::endl;
    using std::cout;
vector<string> &str(vector<string> &v,const string &a)
{
  string line;
  ifstream in(a);
  while(in>>line)
  {
    v.push_back(line);
  }
  return v;
  in.close();
}
int main()
{
  vector<string> v1;
str(v1,"test.txt");
cout<<v1[0]<<endl;
return 0;
}
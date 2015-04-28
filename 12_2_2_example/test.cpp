#include<string>
#include<iostream>
using namespace std;
int main()
{
  const int n=10;
  string * const p =new string[n];
  string s;
  string *q=p;
  while(cin>>s&&q!=p+n)
  {
      *q++=s;//µÈ¼ÛÓÚ*q=s;q++;
  }
  const size_t size = q-p;
  cout<<size;
  delete []p;
}
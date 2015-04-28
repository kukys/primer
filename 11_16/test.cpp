#include<map>
#include<iostream>
using namespace std;
int main()
{
  map<string,int>m={{"yang",12}};
  auto map_it=m.begin();
    map_it->second=100;
}
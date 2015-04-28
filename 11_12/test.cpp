#include<utility>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
  vector<pair<string,int> >vec;
  string name;
  int number;
  while(cin>>name>>number)
  {
    //vec.push_back({name,number});first
    //vec.push_back(pair<string,int>(name,number));second
    vec.push_back(make_pair(name,number));
  }
  for(auto &c :vec)
    {
      cout<<c.first<<" "<<c.second<<endl;
    }   
    return 0;    
}
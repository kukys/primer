#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<cctype>
#include<utility>
using namespace std;
int main()
{
  map<string,vector<pair<string,string>>>Famliy;
  string Fname,Cname,Birthday,answer;
  do
  {
     cout << "请输入姓，名，生日，以空格或者回车格开："; 
     cin>>Fname>>Cname>>Birthday;
      Famliy[Fname ].push_back({Cname,Birthday});
     for (const auto &w : Famliy)  
        {  
            cout <<"家庭的姓为："<< w.first << " "<<"有这些孩子的名:"<<" ";  
            for (const auto &a : w.second)  
                cout << a.first << "生日为"<<a.second;  
            cout << endl;  
        }  
  cout<<"是否添加成员，或家庭(Y/N)"<<endl;
  cin>>answer;
  }while(answer[0]!='n');
  return 0;
}
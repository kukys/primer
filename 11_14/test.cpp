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
     cout << "�������գ��������գ��Կո���߻س��񿪣�"; 
     cin>>Fname>>Cname>>Birthday;
      Famliy[Fname ].push_back({Cname,Birthday});
     for (const auto &w : Famliy)  
        {  
            cout <<"��ͥ����Ϊ��"<< w.first << " "<<"����Щ���ӵ���:"<<" ";  
            for (const auto &a : w.second)  
                cout << a.first << "����Ϊ"<<a.second;  
            cout << endl;  
        }  
  cout<<"�Ƿ���ӳ�Ա�����ͥ(Y/N)"<<endl;
  cin>>answer;
  }while(answer[0]!='n');
  return 0;
}
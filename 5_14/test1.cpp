
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string maxStr,Str1,Str2;
    int maxNum,Num1,Num2;
    if(cin>>Str1)
    Num1=1;
    maxNum=0;
    while(cin>>Str2)
    {
        Num2=1;
        if(Str2==Str1) //����ڶ����ַ����͵�һ��һ���� ������һ��
        	{ 
            Num2=++Num1;
          }
        if(Num1>maxNum)
        {
            maxStr=Str1;
            maxNum=Num1;
        }
        if(Str1!=Str2)
        {
            Str1=Str2;
            Num1=Num2;
        }
    }
    if(maxNum==1)
    	{
    		cout<<"û�������ظ����ַ�";
    	}
    	else{
    cout<<"max string:"<<maxStr<<"  number :"<<maxNum<<endl;
  }
    return 0;
}
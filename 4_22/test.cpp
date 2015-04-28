#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
	using std::string;
int main()
{
	/*int grade;
	while(cin>>grade){
	string finalgrade =(grade>75)?"high pass":(grade>60&&grade<75)?"low pass":"fail";
		cout<<finalgrade;
		cout<<endl;
}*/
int grade;
string finalgrade;
while(cin>>grade)
{
	if(grade>=75)
		{
			finalgrade="hige pass";
		}
	 else if(grade>60&&grade<75)
	 	{
	 		finalgrade="low pass";
	 	}
	 	 else 
	 	 	{
	 	 		finalgrade="fail";
	 	 	}
	cout<<finalgrade<<endl;
}
return 0;
}
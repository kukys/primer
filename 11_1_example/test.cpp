#include <iostream>  
#include <map>  
#include <string>  
#include <algorithm>  
  
using namespace std;  
  
bool isshorter(char a, char b)  
{  
    return a > b;  
}  
  
int main()  
{  
    map<string, size_t>word_count;  
    string word;  
    string s(",.");  
    string::size_type pos;  
    while(cin >> word)  
    {  
        //ת����Сд  
        transform(word.begin(), word.end(), word.begin(), ::tolower);  
        //auto cnt = count_if(word.begin(), word.end(), ::isalpha);   //��һ��ȥ����㣬���Ǳ��ֻ�������ϸ�����ĩβ  
        //word.erase(cnt, word.size()-cnt);  
        while((pos = word.find_first_of(s)) != string::npos)          //�ڶ���ȥ����㣬λ�ö����ԡ���string�������С�  
        {  
            word.erase(pos,1);  //erase������ԭ��
            //string& erase ( size_t pos = 0, size_t n = npos );
            //erase(pos,n); ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�.
        }  
          
        ++word_count[word];  
    }  
    for(const pair<string, size_t> &p : word_count)  
    {  
        cout << "word:" << p.first << " times:" << p.second << endl;  
    }  
}
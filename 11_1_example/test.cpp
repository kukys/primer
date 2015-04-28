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
        //转换成小写  
        transform(word.begin(), word.end(), word.begin(), ::tolower);  
        //auto cnt = count_if(word.begin(), word.end(), ::isalpha);   //第一种去除标点，但是标点只能像题上给的在末尾  
        //word.erase(cnt, word.size()-cnt);  
        while((pos = word.find_first_of(s)) != string::npos)          //第二种去除标点，位置都可以。在string操作里有。  
        {  
            word.erase(pos,1);  //erase函数的原型
            //string& erase ( size_t pos = 0, size_t n = npos );
            //erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符.
        }  
          
        ++word_count[word];  
    }  
    for(const pair<string, size_t> &p : word_count)  
    {  
        cout << "word:" << p.first << " times:" << p.second << endl;  
    }  
}
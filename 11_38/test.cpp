#include<unordered_map>
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void word_transform(ifstream &map_file,ifstream &input);//管理转化过程,第一个参数是单词转换文件，
                                                       //第二个是绑定到需要转换的文件.

unordered_map<string,string> buildMap(ifstream &map_file);         //建立转换映射

const string &
transform(const string &s,const unordered_map<string,string> &m);//进行转换工作

void word_transform(ifstream &map_file,ifstream &input)
{
  auto trans_map = buildMap(map_file);                //保存转化规则
  string text;
  while(getline(input,text))                          //读取一行输入
  {
    std::istringstream str(text);                       
    string word;
    bool firstword =true;                             //控制是否打印空格
    while(str>>word)
    {
    if(firstword)
      {
        firstword=false;
      }
    else
      {
        cout<<" ";
      }
      cout<<transform(word,trans_map);
    }
    cout<<endl;
  }
}

unordered_map<string,string> buildMap(ifstream &map_file)
{
  unordered_map<string,string>trans_map;        //保存转换规则
  string key;                         //要转换的单词
  string value;                       //要替代的单词
  //把第一个单词读取到key，剩余的读取到value
  while(map_file>>key&&getline(map_file,value))
  if(value.size()>1)
    {
      trans_map.insert({key,value.substr(1)});
      //trans_map[key]=value.substr(1);
    }
    else
      {
        throw runtime_error("no rule for" +key);
      }
      return trans_map;
}

const string &
transform(const string &s,const unordered_map<string,string> &m)
{
  //实际的转换工作
  auto map_it=m.find(s);
  //map<string,string>::iterator 
  if(map_it!=m.cend())
    {
      return map_it->second;
    }
    else
      return s;
}
int main()
{
  ifstream in("map_file.txt");
  ifstream out("input.txt");
  word_transform(in,out);
}
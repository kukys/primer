#include<unordered_map>
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void word_transform(ifstream &map_file,ifstream &input);//����ת������,��һ�������ǵ���ת���ļ���
                                                       //�ڶ����ǰ󶨵���Ҫת�����ļ�.

unordered_map<string,string> buildMap(ifstream &map_file);         //����ת��ӳ��

const string &
transform(const string &s,const unordered_map<string,string> &m);//����ת������

void word_transform(ifstream &map_file,ifstream &input)
{
  auto trans_map = buildMap(map_file);                //����ת������
  string text;
  while(getline(input,text))                          //��ȡһ������
  {
    std::istringstream str(text);                       
    string word;
    bool firstword =true;                             //�����Ƿ��ӡ�ո�
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
  unordered_map<string,string>trans_map;        //����ת������
  string key;                         //Ҫת���ĵ���
  string value;                       //Ҫ����ĵ���
  //�ѵ�һ�����ʶ�ȡ��key��ʣ��Ķ�ȡ��value
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
  //ʵ�ʵ�ת������
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
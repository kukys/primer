#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>  
  
using std::vector;  
using std::string;  
using std::ifstream;  
using std::ofstream;  
using std::istringstream;  
using std::ostringstream;  
using std::endl;  
  
struct PersonInfo{  
    string name;  
    vector<string> phones;  
};  
  
  
  
int main(int argc,char **argv)  
{  
    ifstream finput("test1.txt");  
    ofstream foutput("test2.txt",std::ofstream::app);  
  
    string line, word;  
    vector<PersonInfo> people;  
    while (getline(finput, line))  
    {  
        PersonInfo info;  
        istringstream record(line);  
        record >> info.name;  
        while (record >> word)  
            info.phones.push_back(word);  
        people.push_back(info);  
    }  
      
    for (const auto &a : people)  
    {  
        ostringstream ostr;  
        for (const auto &b : a.phones)  
        {  
            ostr <<" "<< b;  
        }  
        foutput << a.name << " " << ostr.str() << endl;  
    }  
  
    return 0;  
}  
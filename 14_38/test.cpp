/*
14——38 39
 */
#include "test.h"
int main()
{
    ifstream in("test.txt");
    string str;
    vector<string> vec;
    int arr;
    while(in>>str)
        vec.push_back(str);
    stable_sort(vec.begin(), vec.end(),[](const string& a,
                const string& b)
                {return a.size()<b.size();});
    size_t i=(*(vec.end()-1)).size();
    cout <<i<<endl;
    for(size_t j=0;j<9;++j)
    {
        arr=count_if(vec.begin(),vec.end(),Length(j+1));
        if(arr)
        cout<<"长度为"<<j+1<<"的有"<<arr<<"个"<<endl;
    }
    /**
     * size_t minnum=0;
    size_t maxnum=0;
    for(size_t j=0;j<=9;++j)
    {
        arr=count_if(vec.begin(),vec.end(),Length(j+1));
        minnum+=arr;
        //if(arr)
        //cout<<"长度为"<<j+1<<"的有"<<arr<<"个"<<endl;
    }
    cout<<"长度为1~9的有"<<minnum<<"个"<<endl;
    for(size_t j=10;j<=i;++j)
    {
        arr=count_if(vec.begin(),vec.end(),Length(j+1));
        maxnum+=arr;
        //if(arr)
        //cout<<"长度为"<<j+1<<"的有"<<arr<<"个"<<endl;
    }
    cout<<"长度>10的有"<<maxnum<<"个"<<endl;
     */
    cout<<endl;
    return 0;
}

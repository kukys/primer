#include"test.h"
#include<algorithm>
#include<vector>
using std::vector;
using std::sort;
int main()
{
    HasPtr h;
    HasPtr hh(h);
    hh=h;
    swap(h,hh);
    vector<HasPtr> vec={h,hh};
    sort(vec.begin(),vec.end());
    return 0;
}
#include<string>
#include<iostream>
#include<memory>
using namespace std;
int main()
{
  const int n=10;
  allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  auto q=p;
  while(cin>>s&&q!=p+n)
  {
    alloc.construct(q++,s);
  }
  const size_t size = q-p;
  cout<<size;
  while(q!=p)
  {
    alloc.destroy(--q);
  }
  alloc.deallocate(p,n);
}
#include <iostream>
using namespace std;
template <typename T,unsigned N>
T* mbegin( T(&t)[N])
{
  return t;
}
template <typename T,unsigned N>
T* mend( T(&t)[N])
{
  return t+N;
}
template <typename T,unsigned N>
int msize( T(&t)[N])
{
  return N;
}
int main(int argc, char const *argv[])
{
  int ar[5]={1,2,3,4,5};
  cout<<*(mbegin(ar))<<endl;
  cout<<*(mend(ar)-1)<<endl;
  cout<<msize(ar)<<endl;
  return 0;
}

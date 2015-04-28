#ifndef TEST_H
#define TEST_H
class Equal
{
public:
  Equal(int i,int j):first(i),second(j){}
  int operator()(int &c) const
  {
    if(first==c) c=second;
    return c;
  }
private:
  int first,second;
};
#endif //TEST_H

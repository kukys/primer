#include"My_13_27.h"

/*HasPtr::~HasPtr()
  {
    if(--*use==0)
      {
        delete ps;
        delete  use;
      }
  }*/
  HasPtr&HasPtr::operator =(const HasPtr &rps)
    {
    //  ++*rps.use;//�����Ҳ������������ü���
     /* if(--*use==0)
        {
          delete ps;//���û�������û�
          delete use;//�ͷű����������ڴ�
        }*/
        ps=rps.ps;
        i=rps.i;
        use=rps.use;
        return *this;
    }
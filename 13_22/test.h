#ifndef TEST_H
#define TEST_H
#include<string>
class HasPtr
{
  public:
    Hasptr  (const std::string  &s  = std::string()):
    ps(new std::string  (s)),i(0) {}
  Hasptr(const Hasptr &hp):ps(new std::string(*hp.ps)),i(hp.i){}
      Hasptr &operator=(const Hasptr&hp) 
      {
        auto hp=new std::string(*hp.ps);//û���ͷ�ps�ľ��ڴ棬������Ƿ���ps�У�����hp ��
          i=hp.i;                                               //û�з���ֵ������������
      }  
    private:
        std ::string*ps;
          int i;
}

#endif //TEST_H 
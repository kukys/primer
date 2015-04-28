#ifndef TEST_H
#define TEST_H
#include<string>
class HasPtr
{
  public:
    HasPtr  (const std::string  &s  = std::string()):
    ps(new std::string  (s)),i(0) {}
  HasPtr(const HasPtr &hp):ps(new std::string(*hp.ps)),i(hp.i){}
      HasPtr &operator=(const HasPtr&hp) 
      {
        auto n=new std::string(*hp.ps);//�Ȱ�ֵ�洢һ����ʱ������
          delete ps;                                        //�ͷŵ�ǰ��ֵ�ڴ�
          //��ɾ���������ں��棬����X=X��������£����ݵĶ�ʧ
          ps  = n;                                            //��������
          i=hp.i;                                             
          return *this;                                 //���ر�����             
      }  
      ~HasPtr
    private:
        std ::string*ps;
          int i;
};
}

//δ��������������ʹ��ps���ڴ�ò����ͷţ�����ڴ�й©��
//��Ա����ps��ͨ��new�����ڶ�����ʽ�������һ���ڴ棬��Ҫʹ��delete��ʽ��ȥ�ͷš�
//If HasPtr didn't define the copy constructor, when assignment happened, just points copied, the string witch ps points haven't been copied.
#endif //TEST_H /
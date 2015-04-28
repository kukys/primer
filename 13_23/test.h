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
        auto n=new std::string(*hp.ps);//先把值存储一个临时对象中
          delete ps;                                        //释放当前旧值内存
          //将删除操作放在后面，避免X=X特殊情况下，内容的丢失
          ps  = n;                                            //拷贝对象
          i=hp.i;                                             
          return *this;                                 //返回本对象             
      }  
      ~HasPtr
    private:
        std ::string*ps;
          int i;
};
}

//未定义析构函数，使得ps的内存得不到释放，造成内存泄漏。
//成员变量ps是通过new操作在堆上显式分配出的一段内存，需要使用delete显式的去释放。
//If HasPtr didn't define the copy constructor, when assignment happened, just points copied, the string witch ps points haven't been copied.
#endif //TEST_H /
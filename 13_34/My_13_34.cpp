#include"My_13_34.h"
#include<iostream>
using std::cout;
  using std::endl;
void Message ::save (  Folder&f)
{
  folders.insert(&f);       //将给定Folder添加到我们的Folder列表中
  
  f.addMsg(this);           //将本Message添加到f的Message集合中
}
void Message::remove (Folder  & f)
{
  folders.erase(&f) ;  //将给定Folder从我们的Folder列表中删除
  f.remMsg(this);             //将本Message从f的Message集合中删除
}

//将本Message添加到指向m的Folder中
void Message::add_to_Folders (const Message &m)
{
  for(auto  f:m.folders)        //对每个包含m的Folder.
    {
      f->addMsg(this);            //向该Folder添加一个指向本Message的指针
    }
}

Message::Message(const  Message &m):
  contents(m.contents),folders(m.folders)
  {
    add_to_Folders(m);//将本消息添加到指向m的Folder中
  }
  
 //从对应的Folder中删除本Message
 
 void Message::remove_from_Folders ()
 {
  for(auto f  : folders)                //对folders中每个指针，
    {
      f->remMsg(this);                 //从该Folder中删除本Message
    }
 } 
 
 Message::~Message()
  {
    remove_from_Folders();
  }
  
  Message&  Message::operator=(const Message &rhs)
    {
      //通过先删除指针再插入他们来处理自赋值情况
      remove_from_Folders();//更新已有Folder
      contents  = rhs.contents;
      folders = rhs.folders;
      add_to_Folders(rhs);//将本Message添加到那些Folder中
      return *this;
    }
    
    void  swap(Message  &lhs,Message  &rhs)
    {
      using std::swap;
      
      for(auto f:lhs.folders)
        {
          f->remMsg(&lhs);
        }
        for(auto f:rhs.folders)
          {
            f->remMsg(&rhs);
          }
         //交换contens和Folders指针set
         
         swap(lhs.folders,rhs.folders);//调用swap(set&,set&)
         swap(lhs.contents,rhs.contents);//调用swap(string&,string&)
         //将每个Message的指针添加到它的新Folder中
         for(auto f :lhs.folders)
          {
            f->addMsg(&lhs);
          }
          for(auto f :rhs.folders)
          {
            f->addMsg(&rhs);
          }
    }
    void Message::print_debug()
        {
    std::cout << contents << std::endl;
          }
      void Folder::add_to_Message(const Folder&f)
        {
            for(auto m  :f.message)
              {
                m->addFldr(this);
              }       
        }
        Folder::Folder(const Folder &f):message(f.message)
          {
            add_to_Message(f);
          }
        void Folder::remove_to_Message()
          {
            for(auto m  :message)
              {
                m-> remFldr(this);
              }      
          }
          Folder::~Folder()
            {
              void remove_to_Message();
            }
           Folder&Folder::operator=(const Folder&f)
            {
              remove_to_Message();
              message = f.message;
              add_to_Message(f);
              return *this;
            }
          void  swap( Folder  &lhs, Folder  &rhs)
          {
            using std::swap;
            for(auto f:lhs.message)
              {
                f->remFldr(&lhs);
              }
              for(auto f:rhs.message)
                {
                  f-> remFldr(&rhs);
                }
             swap(lhs.message,rhs.message);//调用swap(set&,set&)
             
              for(auto f:lhs.message)
                {
                  f->addFldr(&lhs);
                }
                for(auto f:rhs.message)
                {
                  f->addFldr(&rhs);
                }
          }
          void Folder::print_debug()
            {
              for (auto m : message)
                   std::cout << m->contents << " ";
                  std::cout << std::endl;
            }
          int main()
          {
            Message("yang");
            Folder f;
            return 0;
          }
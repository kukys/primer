#ifndef MY_13_34_H
#define MY_13_34_H
#include<string>
#include<set>
class Folder;

class Message 
{
  friend class  Folder;
  friend void  swap(Message  &,Message  &);
  friend void  swap(Folder  &,Folder  &);
  public:
    //folder����ʽ��ʼ��Ϊ�ռ���
    explicit Message( const std::string &str = " "):
                  contents(str){ }
   //�������Ƴ�Ա,��������ָ��Message��ָ��
   Message(const  Message&);            //�������캯��
   
   Message&operator = (const  Message&);//������ֵ�����
   
   ~Message();        //��������
   
   //�Ӹ���Folder���������/ɾ����Message��
   void save(Folder&);
   void remove (Folder&);
   
   private:
    std::string contents;       //ʵ����Ϣ�ı�
    std::set<Folder*> folders;  //������Message��Folder
      
      //�������캯�������������������������ʹ�õĹ��ߺ���
      //����Message ��ӵ�ָ�������Folder��
      void  add_to_Folders(const  Message&);
      //��folders�е�ÿ��Folder��ɾ����Message
      void  remove_from_Folders();
      
     void addFldr(Folder *f) {  folders.insert(f); }
    void  remFldr(Folder *f) {  folders.erase(f); }
       void print_debug();
   
};
void  swap(Message  &,Message  &);
class Folder
{
  friend class Message ;
  friend  void swap( Folder  &, Folder  &);
    friend void  swap(Message  &,Message  &);
  public:
   Folder()=default;
    
    Folder(const Folder&);
    
    Folder&operator=(const Folder&);
   
   ~Folder();
   
  private:
    std::set<Message*>message;      //������message
    void addMsg(Message *m) { message.insert(m); }
    void remMsg(Message *m) { message.erase(m); }
    void add_to_Message(const Folder&);
    void remove_to_Message();
     void print_debug();
};
void  swap( Folder  &, Folder  &);
#endif//MY_13_34_H
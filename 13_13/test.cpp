/*
*����ӿ������������������������дһ�������Բ�ͬ�ķ�ʽʹ��X�Ķ��󣺽�������Ϊ������
�����ò����Ĵ���;��̬��������;�����Ǵ����������;�������.�۲��������,֪�������ʲôʱ��
��ʹ�ÿ���������Ƴ�Ա,�Լ�Ϊʲôʹ������.��ס�����������Թ��Կ������캯���ĵ���.
*/
#include"test.h"
#include<memory>
#include<vector>
using std::shared_ptr;
  using std::make_shared;
    using std::vector;
int main()
{
  /*X	t(5);
  X	c(t);
  c=t;*/
  X t;
  X c=t;//ֻ���п����������и�ֵ
  /*X *p = new X();
  auto p2 = make_shared<X>();
  X item(*p);                         //�������캯����*p������itrm��
  vector<X>vec;
  vec.push_back(*p2);      //����p2ָ��Ķ���
  delete p;*/
  return 0;
}
/*
ϰ��13_14 _15_16 _17
��Ϥ�������캯����
*/
#ifndef TEST_H
#define TEST_H
#include <algorithm>  
class	numbered{
	public:
	numbered(){static int i=0;mysn=i+5;};
     numbered(const numbered&s){mysn=s.mysn+2;};
	int mysn;
};
#endif //TEST_h
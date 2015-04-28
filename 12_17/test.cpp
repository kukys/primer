/*下面unique_ptr声明中，哪些是合法的，
哪些可能导致后续的程序错误？
解释每个错误的问题在哪里。
*/
int ix = 1024, *pi = &ix, *pi2 = new int(2048);  
typedef unique_ptr<int> IntP;  
(a)IntP p0(ix);  
(b)IntP p1(pi);  
(c)IntP p2(pi2);  
(d)IntP p3(&ix);  
(e)IntP p4(new int(2048));  
(f)IntP p5(p2.get());  
解答：
//(a) 非法，不能将int型变量直接拷贝给unique_ptr
//(b) 非法，ix是从栈上分配出来的，在程序结束的时候会自行销毁。当放入智能指针后，程序结束时会产生重复释放的问题。（感谢stienian的提醒）
//(c) 合法
//(d) 非法，原因同(b)
//(e) 合法
//f)  非法，会产生二次销毁的错误。永远也不要用get来初始化另一个指针
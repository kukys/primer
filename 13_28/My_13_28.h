#ifndef MY_13_28_H
#define MY_13_28_H
#include<memory>
class TreeNode {
  public:
    TreeNode();
    TreeNode(const &TreeNode tree):
      value(tree.value),count(tree.count),left(tree.left),right(tree.right){}
      
    TreeNode&operator=(const TreeNode &rhs)
    {//像值一样的传递
     /* auto lnew = rhs.left;
      delete  left;
      left  = lnew;
      auto rnew = rhs.right;
      delete  right;
      right  = rnew;
      vlaue=  rhs.value;
      count = rhs.count;
      return *this;*/
      //像指针一样
      
    }
  private:
    std::string value;
    int               count; 
    TreeNode   *left;
    TreeNode   *right;
    shared_ptr<std:;size_t>*use;
};

#endif//MY_13_28_H
/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A stack class header implementation to be used in the functions of the BST class
*/
#ifndef STACK_HEADER
#define STACK_HEADER

#include "Queue.h"
class Stack
{
private:
    ListNode* top;
    int size;
public:
    Stack();
    Stack(const Stack& left);
    ~Stack();
    void push(TreeNode* treeNode);
    void pop();
    TreeNode* getTop();
    int getSize();
};
#endif
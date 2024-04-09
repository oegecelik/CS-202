/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A queue class header to be used in the functions of the BST class
*/
#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "ListNode.h"
class Queue{
public:
    Queue();
    Queue(Queue& left);
    ~Queue();
    int getSize();
    void enqueue(TreeNode* a);
    void dequeue();
    TreeNode* getTop();
private:
    ListNode* top;
    ListNode* rear;
    int size;
};

#endif
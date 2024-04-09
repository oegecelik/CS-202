/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A queue class to be used in the functions of the BST class
*/
#include "Queue.h"

Queue::Queue()
{
    top = nullptr;
    rear = nullptr;
    size = 0;
}

Queue::Queue(Queue &left)
{
    this->top = nullptr;
    this->rear = nullptr;
    this->size = 0;
    ListNode* leftcur = left.top;
    if(leftcur == nullptr)
        return;
    while(leftcur != nullptr){
        enqueue(leftcur->item);
        leftcur = leftcur->next;
    }
}

Queue::~Queue()
{
    while(top != nullptr){
        dequeue();
    }
    top = nullptr;
    rear = nullptr;
}

int Queue::getSize()
{
    return size;
}

void Queue::enqueue(TreeNode* a)
{
    if(top == nullptr){
        ListNode* newNode = new ListNode(a);
        top = newNode;
        rear = newNode;
    }
    else{
        rear->next = new ListNode(a);
        rear = rear->next;
    }
    size++;
}

void Queue::dequeue()
{
    if(top != nullptr){
        ListNode* temp = top->next;
        delete top;
        top = temp;
        size--;
    }
}

TreeNode* Queue::getTop()
{
    return top->item;
}

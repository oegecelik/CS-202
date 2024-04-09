/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A stack class implementation to be used in the functions of the BST class
*/
#include "Stack.h"

Stack::Stack()
{
    top = nullptr;
    size = 0;
}

Stack::Stack(const Stack &left)
{
    ListNode* leftcur = left.top;
    if(leftcur == nullptr){
        this->top = nullptr;
        this->size = 0;
    }
    this->top = new ListNode(leftcur->item);
    ListNode* cur = this->top;
    this->size = 1;
    while(leftcur->next != nullptr){
        this->size++;
        leftcur = leftcur->next;
        cur->next = new ListNode(leftcur->item);
        cur = cur->next;
    }
    cur->next = nullptr;
}

Stack::~Stack()
{
    while(top != nullptr){
        pop();
    }
}

void Stack::push(TreeNode *treeNode)
{
    if(top == nullptr){
        top = new ListNode(treeNode);
    }
    else{
        ListNode* temp = top;
        top= new ListNode(treeNode);
        top->next = temp;
    }
    size++;
}

void Stack::pop()
{
    if(top != nullptr){
        ListNode* delPtr = top;
        top = top->next;
        delete delPtr;
        delPtr = nullptr;
        size--;
    }
}

TreeNode* Stack::getTop()
{
    if(top != nullptr){
        return top->item;
    }
    else{
        return nullptr;
    }
}

int Stack::getSize()
{
    return size;
}

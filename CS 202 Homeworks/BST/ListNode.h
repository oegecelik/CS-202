/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A node class header that can be used in list data structures.
*/
#ifndef LIST_NODE
#define LIST_NODE

#include "TreeNode.h"

class ListNode{
public:
    ListNode(TreeNode* item);
    ListNode();
    ~ListNode();
    ListNode* next;
    TreeNode* item;
};

#endif
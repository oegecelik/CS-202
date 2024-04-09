/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A node class implementation that can be used in list data structures.
*/
#include "ListNode.h"

ListNode::ListNode(TreeNode *item)
{
    this->item = item;
    next = nullptr;
}

ListNode::ListNode()
{
    next = nullptr;
    item = nullptr;
}

ListNode::~ListNode()
{
    next = nullptr;
    item = nullptr;
}

/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A tree node class header to be used as the primary node of a binary search tree
*/
#ifndef TREE_NODE
#define TREE_NODE

#include <iostream>
using namespace std;

class TreeNode{
private:
    TreeNode();
    TreeNode(int key, int height);
    TreeNode(int key,  TreeNode* left, TreeNode* right);
    ~TreeNode();
    int key;
    int height;
    TreeNode* leftChildPtr;
    TreeNode* rightChildPtr;
    friend class BST;
};
#endif
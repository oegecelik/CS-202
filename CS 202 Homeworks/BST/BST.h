/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 1
* Description : A binary search tree class.
*/
#ifndef BST_H
#define BST_H

#include "Stack.h"
using namespace std;

class BST{
public:
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A, int B);        
    int getMaxLevel();
    void insertHelperNoOutput(TreeNode*& nodePtr, int newItem, int curLevel);
    TreeNode* root; 
private:
    int maxLevel;
    void preorderTraverse(TreeNode*& nodePtr, Stack& stack, int& max, int cur, Stack*& maxStack);
    void insertHelper(TreeNode*& nodePtr, int newItem, int curLevel);
    void deleteHelper(TreeNode*& nodePtr, int key);
    void deleteNodeItem(TreeNode*& nodePtr);
    void destroyTree(TreeNode*& nodePtr);
    void inorderTraverse(TreeNode* nodePtr, string& output);
    

    
};
#endif
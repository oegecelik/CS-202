/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : A tree node class implementation to be used as the primary node of a binary search tree
*/
#include "TreeNode.h"
TreeNode::TreeNode():key{0}, height{0}, leftChildPtr{nullptr}, rightChildPtr{nullptr}
{}
TreeNode::TreeNode(int key, int height):key{key}, height{height}, leftChildPtr{nullptr}, rightChildPtr{nullptr}
{}
TreeNode::TreeNode(int key, TreeNode* left, TreeNode* right): key{key}, height{0}, leftChildPtr{left}, rightChildPtr{right}
{}
TreeNode::~TreeNode()
{
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

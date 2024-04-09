/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : BST implementation file
*/
#include "BST.h"
#include <cmath>
BST::BST(int keys[], int size)
{
    maxLevel = 0;
    if(size <= 0){
        root = nullptr;
        return;
    }
    root = new TreeNode(keys[0], 1);
    for(int i = 1; i<size; i++){
        insertHelperNoOutput(root, keys[i], 0);
    }
    cout << "BST with size " << size << " is created." << endl;
}

BST::~BST()
{
    destroyTree(root);
}

void BST::insertKey(int key)
{
    insertHelper(root, key, 0);
}

void BST::deleteKey(int key)
{
    deleteHelper(root, key);
}

void BST::displayInorder()
{
    string output = "";
    cout<<"Inorder display is: ";
    inorderTraverse(root, output);
    output.pop_back();
    output.pop_back();
    cout<<output<<endl;
}

void BST::findFullBTLevel()
{
    if(root == nullptr){
        cout<< "Full binary tree level is: 0" <<endl; 
        return;
    }
    else{
        Queue queue;
        bool maxHeightReached = false;
        int count = 1;
        queue.enqueue(root);
        while(!maxHeightReached){
            if(queue.getTop()->leftChildPtr != nullptr && queue.getTop()->rightChildPtr != nullptr){
                queue.enqueue(queue.getTop()->leftChildPtr);
                queue.enqueue(queue.getTop()->rightChildPtr);
                queue.dequeue();
                count += 2;
            }
            else{
                maxHeightReached = true;
            }
        }
        double temp = log2(static_cast<double>(count));
        count = temp + 1;
        cout<< "Full binary tree level is: " << count << endl;
    }

}

void BST::lowestCommonAncestor(int A, int B)
{
    if(root == nullptr)
        return;
    bool found = false;
    TreeNode* curNode = root;
    int ancestor = root->key;
    while(!found){
        if(A == curNode->key || B == curNode->key || 
        (A < curNode->key && B > curNode->key) || (A > curNode->key && B < curNode->key)){
            found = true;
            ancestor = curNode->key;
        }
        else if(A < curNode->key && B < curNode->key){
            if(curNode->leftChildPtr == nullptr){
                found = true;
                ancestor = curNode->key;
            }
            else{
                curNode = curNode->leftChildPtr;
            }
        }
        else{
            if(curNode->rightChildPtr == nullptr){
                found = true;
                ancestor = curNode->key;
            }
            else{
                curNode = curNode->rightChildPtr;
            }
        }
    }
    cout << "Lowest common ancestor of " << A << " and " << B << " is: " << ancestor << endl;
   
}

void BST::maximumSumPath()
{
    Stack curStack;
    Stack* maxStack = nullptr;
    int max = 0;
    int& maxHandle = max;
    int cur = 0;
    if(root != nullptr){
        preorderTraverse(root, curStack, maxHandle, cur, maxStack);
    }
    Stack reversedMax;
    while (maxStack->getTop() != nullptr){
        reversedMax.push(maxStack->getTop());
        maxStack->pop();
    }
    delete maxStack;
    cout << "Maximum sum path is: ";
    if(reversedMax.getSize() != 0){
        cout << reversedMax.getTop()->key;
        reversedMax.pop();
    }
    while(reversedMax.getTop() != nullptr){
        cout << ", " << reversedMax.getTop()->key;
        reversedMax.pop();
    }
    cout<<endl;
}
void BST::preorderTraverse(TreeNode*& nodePtr, Stack& curStack, int& max, int cur, Stack*& maxStack){
    //Should not happen, just for safety
    if(nodePtr == nullptr){
        return;
    }

    curStack.push(nodePtr);
    cur += nodePtr->key;
    //If this is a leaf node:
    if(nodePtr->leftChildPtr == nullptr && nodePtr->rightChildPtr == nullptr){
        if(cur>max){
            max = cur;
            if(maxStack)
                delete maxStack;
            maxStack = new Stack(curStack);
        }
        //else do nothing, since this is not a max sum path.
    }

    //If the node only has a left child:
    else if(nodePtr->rightChildPtr == nullptr){
        preorderTraverse(nodePtr->leftChildPtr, curStack, max, cur, maxStack);
    }

    //If the node only has a right child:
    else if(nodePtr->leftChildPtr == nullptr){
        preorderTraverse(nodePtr->rightChildPtr, curStack, max, cur, maxStack);
    }
    
    //If the node has both children:
    else{
        preorderTraverse(nodePtr->leftChildPtr, curStack, max, cur, maxStack);
        preorderTraverse(nodePtr->rightChildPtr, curStack, max, cur, maxStack);
    }
    cur -= curStack.getTop()->key;
    curStack.pop();
}
void BST::maximumWidth()
{
    if(root == nullptr){
        cout << "Maximum level is: 0" << endl; 
    }
    int maxWidth = 1;
    Queue* curQueue = new Queue();
    curQueue->enqueue(root);
    Queue* maxQueue = new Queue(*curQueue);
    Queue* parents = new Queue(); // Just to reduce an if statement from the loop
    while(curQueue->getSize()>0){
        delete parents;
        parents = curQueue;
        curQueue = new Queue();
        while(parents->getSize()>0){
            if(parents->getTop()->leftChildPtr != nullptr){
                curQueue->enqueue(parents->getTop()->leftChildPtr);
            }
            if(parents->getTop()->rightChildPtr != nullptr){
                curQueue->enqueue(parents->getTop()->rightChildPtr);
            }
            parents->dequeue();
        }
        if(curQueue->getSize()>maxWidth){
            delete maxQueue;
            maxQueue = new Queue(*curQueue);
            maxWidth = curQueue->getSize();
        }
        //Else do nothing, in the next iteration parents will be deleted, cur will be transferred to parents, max will remain the same
    }
    cout << "Maximum level is: ";
    cout << maxQueue->getTop()->key;
    maxQueue->dequeue();
    while(maxQueue->getSize()>0){
        cout << ", " << maxQueue->getTop()->key;
        maxQueue->dequeue();
    }
    cout << endl;
    delete curQueue;
    delete maxQueue;
    delete parents;
}

void BST::pathFromAtoB(int A, int B)
{
    if(root == nullptr)
        return;
    Stack stackA;
    Queue queueA;
    Queue queueB;

    bool isAFound = false;
    bool isBFound = false;
    TreeNode* curNode = root;

    while(!isAFound){
        stackA.push(curNode);
        queueA.enqueue(curNode);
        if(A == curNode->key){
            isAFound = true;
        }
        else if(A < curNode->key){
            if(curNode->leftChildPtr == nullptr){
                return;
            }
            else{
                curNode = curNode->leftChildPtr;
            }
        }
        else{
            if(curNode->rightChildPtr == nullptr){
                return;
            }
            else{
                curNode = curNode->rightChildPtr;
            }
        }
    }

    curNode = root;

     while(!isBFound){
        queueB.enqueue(curNode);
        if(B == curNode->key){
            isBFound = true;
        }
        else if(B < curNode->key){
            if(curNode->leftChildPtr == nullptr){
                return;
            }
            else{
                curNode = curNode->leftChildPtr;
            }
        }
        else{
            if(curNode->rightChildPtr == nullptr){
                return;
            }
            else{
                curNode = curNode->rightChildPtr;
            }
        }
    }
    int commonAncestorKey = queueA.getTop()->key;
    while(queueA.getTop() == queueB.getTop()){
        commonAncestorKey = queueA.getTop()->key;
        queueA.dequeue();
        queueB.dequeue();
    }
    cout << "Path from " << A << " to " << B << " is: ";
    cout << stackA.getTop()->key; 
    int check = stackA.getTop()->key;  
    stackA.pop();

    while(stackA.getTop()->key != commonAncestorKey){
        cout << ", " << stackA.getTop()->key;
        stackA.pop();
    }
    if(check != commonAncestorKey)
        cout << ", " << commonAncestorKey;
    while(queueB.getSize()>0){
        cout << ", " << queueB.getTop()->key;
        queueB.dequeue();
    }
    cout << endl;
}

void BST::insertHelperNoOutput(TreeNode *& nodePtr, int newItem, int curLevel)
{
    curLevel++;
    //if the node is null, insert new item, else give the reference of parent's child
    //and try insertion again.
    if(nodePtr == nullptr){
        if(curLevel > maxLevel){
            maxLevel = curLevel;
        }
        nodePtr = new TreeNode(newItem, curLevel);
        return;
    }
    if(nodePtr->key == newItem){
        return;
    }
    if(nodePtr->key > newItem){
        insertHelperNoOutput(nodePtr->leftChildPtr, newItem, curLevel);
    }
    else{
        insertHelperNoOutput(nodePtr->rightChildPtr, newItem, curLevel);
    }
}

int BST::getMaxLevel()
{
    return maxLevel;
}

void BST::insertHelper(TreeNode *&nodePtr, int newItem, int curLevel)
{
    curLevel++;
    //if the node is null, insert new item, else give the reference of parent's child
    //and try insertion again.
    if(nodePtr == nullptr){
        if(curLevel > maxLevel){
            maxLevel = curLevel;
        }
        nodePtr = new TreeNode(newItem, curLevel);
        cout << "Key " << newItem << " is added."<<endl;
        return;
    }
    if(nodePtr->key == newItem){
        cout << "Key " << newItem << " is not added. It exists!" << endl;
        return;
    }
    if(nodePtr->key > newItem){
        insertHelper(nodePtr->leftChildPtr, newItem, curLevel);
    }
    else{
        insertHelper(nodePtr->rightChildPtr, newItem, curLevel);
    }
}

void BST::deleteHelper(TreeNode *& nodePtr, int key)
{
    //Four cases
    //1 - Node doesn't exist
    //2 - Deletion of node with 0 children
    //3 - Deletion of node with 1 child
    //4 - Deletion of node with 2 children
    if(nodePtr == nullptr){
        cout << "Key " << key << " is not deleted. It does not exist!" << endl;
        return;
    }
    else if(key == nodePtr->key){
        deleteNodeItem(nodePtr);
    }
    else if (key < nodePtr->key){
        deleteHelper(nodePtr->leftChildPtr, key);
    }
    else{
        deleteHelper(nodePtr->rightChildPtr, key);
    }

}

void BST::deleteNodeItem(TreeNode *&nodePtr)
{
    TreeNode* delPtr;
    int deletionItem = nodePtr->key;

    //1 - Test for a leaf
    if((nodePtr->leftChildPtr == nullptr) && (nodePtr->rightChildPtr == nullptr)){
        delete nodePtr;
        nodePtr = nullptr;
    }

    //2 - Test for no left child
    else if(nodePtr->leftChildPtr == nullptr){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }

    //3 - Test for no right child
    else if(nodePtr->rightChildPtr == nullptr){
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = nullptr;
        delete delPtr;
    }
    
    //4 - There are two children
    else{
        //First find inorder successor (right subtree's leftmost element)
        delPtr = nodePtr->rightChildPtr; 
        TreeNode* prev = nodePtr;
        while(delPtr->leftChildPtr != nullptr){
            prev = delPtr;
            delPtr = delPtr->leftChildPtr;
        }
        //After finding, replace previous node's left child with deleted node's right child
        nodePtr->key = delPtr->key;
        if(prev == nodePtr) // if prev did not change at all -- the right subtree is visited and the searched value is found
            prev->rightChildPtr = delPtr->rightChildPtr;
        else
            prev->leftChildPtr = delPtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    cout << "Key " << deletionItem << " is deleted."<<endl;

}

void BST::destroyTree(TreeNode *& treePtr) {
		if (treePtr != NULL){
			destroyTree(treePtr->leftChildPtr);
			destroyTree(treePtr->rightChildPtr);
			delete treePtr;
			treePtr = NULL;
		}
}

void BST::inorderTraverse(TreeNode *nodePtr, string& output)
{
    if(nodePtr != nullptr){
        inorderTraverse(nodePtr->leftChildPtr, output);
        output.append(to_string(nodePtr->key));
        output.append(", ");
        inorderTraverse(nodePtr->rightChildPtr,output);
    }
}

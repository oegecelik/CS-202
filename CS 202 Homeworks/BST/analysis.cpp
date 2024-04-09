/**
* Title: Binary Search Trees
* Author : Orhun Ege Çelik
* ID: 12345678
* Section : 3
* Homework : 1
* Description : The implementation file of the analysis header. Prints the time elapsed after 1000 insertions, till 10000 insertions in total.
*/
#include "analysis.h"

void analysis::timeAnalysis()
{
    srand(time(0));
    int randArr[10000];
    bool checkExistance = true;
    //The loop also checks for key existance, if the key exists, the random function will re-generate a random number till the key does not exist.
    for(int i = 0; i<10000; i++){
        randArr[i] = rand();
        int j = 0;
        while(checkExistance){
            if(randArr[i] == randArr[j]){
                randArr[i] = rand();
                j = 0;
            }
            else{
                j++;
            }
            if(j >= i){
                checkExistance = false;
            }
        }
    }
    clock_t t = clock();
    BST bst(nullptr, 0);
    for(int i = 0; i<10000; i++){
        bst.insertHelperNoOutput(bst.root, randArr[i], 0);
        if(i != 0 && i % 1000 == 0){
            t = clock()-t;
            cout << "Max height after 1000 insertions is: " << bst.getMaxLevel() << endl;
            cout << "Time elapsed for 1000 insertions is: " << ((float)t)/CLOCKS_PER_SEC <<endl;
            cout << endl;
            t = clock();
        }
    }
    t = clock()-t;
    cout << "Max height after 1000 insertion is: " << bst.getMaxLevel() << endl;
    cout << "Time elapsed for 1000 insertions is: " << ((float)t)/CLOCKS_PER_SEC <<endl;
}
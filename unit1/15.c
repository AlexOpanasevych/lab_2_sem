/* ----------------------------------------------------------------<Header>-
 Name: .c
 Title: Задача 1.2.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: 
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"
int main(void){
    BinaryTree * btree = addToBTree(1);
    btree->left = addToBTree(2);
    btree->right = addToBTree(3);
    btree->left->left = addToBTree(4);
    btree->left->right = addToBTree(5);
    clock_t start = clock();
    BinaryTree * exem = lookup(btree, 5);
    printf("Time for recursive version - %lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    start = clock();
    BinaryTree * exemtwo = nrlookup(btree, 5);
    printf("Time for iterative version - %lf\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    deleteTree(btree);
    deleteTree(exem);
    deleteTree(exemtwo);
    return 0;
}
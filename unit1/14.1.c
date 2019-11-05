/* ----------------------------------------------------------------<Header>-
 Name: 14.1.c
 Title: Задача 1.14.1.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: элементы поступают в случайном порядке (поступающие данные достаточно
стохастичны). Написать функцию проверки сбалансированности заполненного
(построенного) дерева, чтобы подтвердить или опровергнуть следующее утверждение:
если элементы поступают в случайном порядке, то дерево будет более-менее
сбалансированным.
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

BinaryTree * insertLevelOrder(int arr[], BinaryTree* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) {
        //if(!root) return root;
        BinaryTree * temp = addToBTree(arr[i]); 
        root = temp;
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
int main(){
    BinaryTree * tree = NULL;
    int arr[20] = {10, 15, 76, 174, 32, 43, 55, 33, 21, 1, 5, 6, 2, 67, 45, 90, 1322, 78, 87, 69};
    tree = insertLevelOrder(arr, tree, 0, 20);
    inorder(tree);
    if(checkBalance(tree)) printf("\ntree is balanced\n");
    else printf("tree is not balanced\n");
    deleteTree(tree);
    return 0;
}
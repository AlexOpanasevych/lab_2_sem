/* ----------------------------------------------------------------<Header>-
 Name: 17.c
 Title: Задача 1.17.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Придумайте и реализуйте набор тестов для проверки правильности функций
работы с деревьями, рассмотренных в Unit 1 "Binary search tree" и "Tree-traverser"
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){  
    BinaryTree *tree = addToBTree(2);
    tree->left = addToBTree(3);
    tree->left->left = addToBTree(1);
    tree->left->right = addToBTree(2);
    tree->right = addToBTree(4);
    tree->right->left = addToBTree(7);
    tree->right->right = addToBTree(5);
    BinaryTree * node1 = lookup(tree, 2);
    BinaryTree * node2 = nrlookup(tree, 1);
    inorder(node1);
    inorder(node2);
    checkBalance(tree);
    treeSort(tree);
    inorder(tree);
    deleteTree(tree);
    return 0;
}
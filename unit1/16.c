/* ----------------------------------------------------------------<Header>-
 Name: 16.c
 Title: Задача 1.16.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Напишите функцию сортировки с симметричным обходом (см. Unit 1 "Treetraverser")
. Какой порядок по быстродействию имеет данная операция? При каких
условиях она может работать плохо? Каковы ее характеристики по сравнению с
алгоритмом быстрой сортировки и с библиотечными функциями? 
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    int treeArray[100];  
    int ind = 0;  
    BinaryTree *tree = addToBTree(2);
    tree->left = addToBTree(3);
    tree->left->left = addToBTree(1);
    tree->left->right = addToBTree(2);
    tree->right = addToBTree(4);
    tree->right->left = addToBTree(7);
    tree->right->right = addToBTree(5);
    treesort(tree);
    inorder(tree);
    deleteTree(tree);
    return 0;
}
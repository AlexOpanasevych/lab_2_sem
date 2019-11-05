/* ----------------------------------------------------------------<Header>-
 Name: 14.2.c
 Title: Задача 1.14.2.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: элементы прибывают в отсортированном виде. Написать функцию проверки
сбалансированности заполненного (построенного) дерева, чтобы подтвердить или
опровергнуть следующее утверждение: если элементы прибывают в отсортированном
виде, то спуск всегда будет выполняться до самого низа одной из ветвей дерева,
фактически представляя собой список по указателю right. Этот случай характеризуется
проблемами быстродействия, присущими спискам. 
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    BinaryTree *tree = addToBTree(1);
    tree->left = addToBTree(2);
    tree->left->left = addToBTree(4);
    tree->left->right = addToBTree(5);
    tree->right = addToBTree(3);
    tree->right->left = addToBTree(6);
    tree->right->right = addToBTree(7);
    inorder(tree);
    if(checkBalance(tree)) printf("Tree is balanced\n");
    else printf("Tree is not balanced\n");
    deleteTree(tree);
    return 0;
}
/* ----------------------------------------------------------------<Header>-
 Name: 13.c
 Title: Задача 1.13.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Придумайте и реализуйте набор тестов для проверки правильности
написанных вами функций работы со списками. 
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    Foo * list;
    push(&list, 78);
    push(&list, 2);
    push(&list, 72);
    push(&list, 24);
    push(&list, 56);
    printList(list);
    putchar('\n');
    insertAfter(list, 3, 90);
    printList(list);
    putchar('\n');
    delByID(&list, 5);
    printList(list);
    putchar('\n');
    pushEnd(&list, 90);
    printList(list);
    putchar('\n');
    reverseList(&list);
    printList(list);
    putchar('\n');
    recursiveReverse(&list);
    printList(list);
    putchar('\n');
    Foo * new = copyList(list);
    Foo * merged = mergeList(list, new);
    printList(merged);
    freeList(merged);
    return 0;
}
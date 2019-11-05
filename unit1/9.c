/* ----------------------------------------------------------------<Header>-
 Name: 9.c
 Title: Задача 1.9.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Реализуйте некоторые другие возможные операции со списком (см. Unit 1 "A
singly-linked list"), а именно: копирование, слияние, разбиение, вставку перед конкретным
элементом или после него. Как две различные операции вставки отличаются друг от друга
по сложности? В какой степени можно воспользоваться приведенными в лекции 
функциями, а что придется написать самостоятельно?
ответ внизу
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    Foo * list = NULL, * list1 = NULL, *list2 = NULL;
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    printList(list);
    putchar('\n');
    delByID(&list, 3);
    //breakList(&list, list1, list2, 0);
    printList(list);
    putchar('\n');
    Foo *new = copyList(list);
    Foo *merged = mergeList(new, list);
    printList(merged);
    freeList(merged);
    //freeList(list1);
    //freeList(list2);
    //getchar();
    return 0;
}

// поскольку мы вставляем перед конкретным елементом(время работы О(m)) или после него(O(m+1), частный случай O(n)), 
// вставка в конце О(n), тоесть наибольшая по сложности операция. Можно воспользоваться функцией для очистки памяти
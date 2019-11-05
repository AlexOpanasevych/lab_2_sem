/* ----------------------------------------------------------------<Header>-
 Name: 10.c
 Title: Задача 1.10.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Напишите рекурсивную и итерационную версии функции reverse_list, которая
бы изменяла порядок следования элементов в списке на противоположный. Не
создавайте новых элементов списка — используйте только существующие. 
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h> 
#include <stdlib.h> 
#include "libka/pch.h"

typedef struct Foo Foo;

int main() { 
    Foo* head = NULL; 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3);  
    push(&head, 4);       
    printf("Given linked list\n"); 
    printList(head);     
    reverseList(&head);
    recursiveReverse(&head);                
    printf("\n2 time Reversed Linked list \n"); 
    printList(head);     
    freeList(head);
} 
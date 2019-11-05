/* ----------------------------------------------------------------<Header>-
 Name: 7.c
 Title: Задача 1.7.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Напишите функцию для вывода всех элементов списка (см. Unit 1 "A singlylinked
list"), которая перебирает его и последовательно выводит каждый элемент.
Подсказка: Чтобы вычислить длину списка, можно написать функцию с простым
перебором и инкрементированием счетчика.
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    struct List * list = NULL;
    list = (List*)malloc(sizeof(List));
    list->data = 13;
    list->string = "dergelbemann";
    list->next=NULL;
    printMembers(list);
    return 0;
}
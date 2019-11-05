/* ----------------------------------------------------------------<Header>-
 Name: 11.c
 Title: Задача 1.11.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Как и функция freeall (см. Unit 1 "A singly-linked list"), функция delitem не
освобождает поля name. Модифицируйте обе эти функции с учетом того, что память,
выделенную под поля name, нужно освобождать.
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

int main(){
    List * list = NULL;
    list = newitem("PashaBiceps", 1);
    list->next = newitem("BESTof3", 2);
    list->next->next = NULL;
    printMembers(list);
    delByIDForTask(&list, 0); //my equivalent for "delitem"
    freeListForTask(list);
    return 0;
}
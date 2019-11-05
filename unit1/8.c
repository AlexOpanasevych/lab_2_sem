/* ----------------------------------------------------------------<Header>-
 Name: 8.c
 Title: Задача 1.8.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Напишите функцию coolfun, выполняющую перебор списка (см. Unit 1 "A singlylinked
list") и вызывающую другую заданную функцию для каждого его элемента. Функцию
coolfun сделать гибкой, включив в ее параметры аргумент для передачи в ту, другую
функцию. Таким образом, coolfun будет принимать три аргумента: сам список; указатель
на функцию, вызываемую для каждого элемента списка; аргумент для передачи в эту
функцию. Прототип: void coolfun(Nameval *listp, void (*fn)(Nameval*, void*),
void *arg).
Пример. Для подсчета элементов определяется функция с аргументом в виде указателя на
целочисленный счетчик, который нужно инкрементировать:
/* inccounter: инкрементирует счетчик *arg */
/*void inccounter(Nameval *p, void *arg) {
 int *ip;
  p здесь не используется!
 ip = (int *)arg;
 (*ip)++;
}
Эта функция вызывается следующим образом:
int n = 0;
coolfun(nvlist, inccounter, &n);
printf("%d elements in nvlist\n", n);
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

//typedef struct Foo Foo;

/* inccounter: инкрементирует счетчик *arg */
void inccounter(void *arg) {
    int *ip;
    /* p здесь не используется! */
    ip = (int *)arg;
    (*ip)++;
}

int main() {
    Foo * list1 = NULL;
    Foo * list2 = NULL;
    Foo * list3 = NULL;
    Foo * list4 = NULL;
    list1 = (Foo*)malloc(sizeof(Foo));
    list2 = (Foo*)malloc(sizeof(Foo));
    list3 = (Foo*)malloc(sizeof(Foo));
    list4 = (Foo*)malloc(sizeof(Foo));
    list1->data = 1;
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;
    int n = 0;
    coolfun(list1, inccounter, &n);
    printf("%d elements in nvlist\n", n); 
}
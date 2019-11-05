/* ----------------------------------------------------------------<Header>-
 Name: 6.c
 Title:  Задача 2.6.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Реализуйте на С решение Задачи 2.5. (см. Unit 1 "A singly-linked list").

 ------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Queue;
typedef struct Node Node;

struct Node{
    int data;
    struct Node *next;
};

struct Queue { 
    struct Node *front, *rear; 
}; 

void freeList(Node * list){
    Node *temp;
    while(list){
        temp = list;
        list = list->next;
        free(temp);
    }
}

void freeQueue(Queue * q){
    if(!q) return;
    freeList(q->front);
    freeList(q->rear);
    free(q);
}



void enQueue(Queue *q, int value) { 
    Node *temp = (Node*)malloc(sizeof(Node)); 
    temp->data = value;
    if (q->front == NULL) 
        q->front = temp; 
    else
        q->rear->next = temp;
    q->rear = temp; 
    q->rear->next = q->front; 
} 

int deQueue(Queue *q) { 
    if (q->front == NULL) { 
        printf ("Queue is empty"); 
        return 0; 
    }
    int value; 
    if (q->front == q->rear) { 
        value = q->front->data; 
        free(q->front); 
        q->front = NULL; 
        q->rear = NULL; 
    }
    else{ 
        Node *temp = q->front; 
        value = temp->data; 
        q->front = q->front->next; 
        q->rear->next= q->front; 
        free(temp); 
    } 
    return value ; 
}

void displayQueue(Queue *q){
    if(!q || !q->front) return; 
    Node *temp = q->front; 
    printf("\nElements in Circular Queue are: "); 
    while (temp->next != q->front) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("%d", temp->data); 
} 

int main(void){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    displayQueue(queue);
    deQueue(queue);
    displayQueue(queue);
    deQueue(queue);
    displayQueue(queue);
    deQueue(queue);
    displayQueue(queue);
    freeQueue(queue);
    return 0;
}
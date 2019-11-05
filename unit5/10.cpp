/* ----------------------------------------------------------------<Header>-
 Name: 10.cpp
 Title: Задача 5.10. 
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description:  Создайте односвязный список (см. Unit 1 "A singly-linked list"), используя
new, и реализуйте возможные операции с этим списком, а именно: добавление
элемента, удаление элемента, копирование элемента, слияние, разбиение, вставку
перед конкретным элементом или после него. 
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct List List;

struct List{
    int data;
    List *next;
};

void printMembers(List *list){
    do{
        printf("%d ", list->data);
        list = list->next;
    }while(list != NULL);
    cout << '\n';
}

void push(List** list, int new_data) { 
    List* new_node = new List;            
    new_node->data  = new_data; 
    new_node->next = (*list);     
    (*list)    = new_node; 
}

void delByID(List **list, int position){
    if (*list == NULL) return; 
    List * temp = *list; 
    if (position == 0) { 
        *list = temp->next;    
        delete temp;              
        return; 
    } 
    for (int i=0; temp!=NULL && i < position-1; i++) 
         temp = temp->next;
    if (temp == NULL || temp->next == NULL) return; 
    List *next = temp->next->next;  
    delete temp->next;
    temp->next = next; 
}

List* mergeList(List * a, List * b) { 
    List* result = NULL;
    if (a == NULL) return b; 
    else if (b == NULL) return a; 
    if (a->data <= b->data){ 
        result = a; 
        result->next = mergeList(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = mergeList(a, b->next); 
    }
    return result;
}
List *split_list(List* original){
    if(original == NULL) return NULL;
    List * runner = original->next;
    while (runner !=NULL && runner->next != NULL){
        runner= runner->next->next;
        original = original->next;
    }
    List * toReturn = original->next;
    original->next = NULL;
    return toReturn;
}

void insertAfter(List * list, int new_data, int position){
    List* new_node = new List;
    int count = 0;
    while(list->next != NULL){
        if(count == position){
            new_node->data = new_data;
            new_node->next = list->next;
            list->next = new_node;
            return;
        }
        list = list->next;
        count++;
    }
    printf("Out of list\n");
    return;
}

void insertBefore(List * list, int new_data, int position){
    List* new_node = new List;
    int count = 0;
    while(list->next != NULL){
        if(count == position-1){
            new_node->data = new_data;
            new_node->next = list->next;
            list->next = new_node;
            return;
        }
        list = list->next;
        count++;
    }
    printf("Out of list\n");
    return;
}

List * copyElement(List *list, int id){
    if(list == NULL) return list;
    for(int i = 0; i <= id && list != NULL; i++) list = list->next;
    List * copyNode = new List;
    copyNode->data = list->data;
    copyNode->next = NULL;
    return copyNode;
}

int main(){
    List * list;
    for(int i = 0; i < 10; i++){
        push(&list, i);
    }
    printf("After inserting: \n");
    printMembers(list);
    printf("After deleting elem: \n");
    delByID(&list, 1);
    printMembers(list);
    printf("After inserting after: \n");
    insertAfter(list, 5, 2);
    printMembers(list);
    printf("After splitting: \n");
    List * list1 = split_list(list);
    printMembers(list);
    printMembers(list1);
    printf("After copying: \n");
    List *copy = copyElement(list, 2);
    printMembers(copy);
    printf("After inserting before: \n");
    insertAfter(list, 25, 4);
    printMembers(list);
    printf("After merging: \n");
    List *merged = mergeList(list, list1);
    printMembers(merged);
    delete list;
    return 0;
}

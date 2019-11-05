/*Description : header file for functions in Unit1*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 30011

enum{MULTIPLIER = 31};
typedef struct List List; //for task 1

struct List{ 
    int data;
    char *string;
    struct List *next;
};

List * symtab[SIZE];

typedef struct TypeList TypeList; // for task 12
struct TypeList{
  void *data;
  struct TypeList *next;
};

typedef struct BinaryTree BinaryTree; //FOR TASKS 14-17
struct BinaryTree{
  int data;
  BinaryTree *left;
  BinaryTree *right;
};

typedef struct Foo Foo; // FOR TASKS 1-13
struct Foo{ 
  int data; 
  struct Foo *next; 
};

bool isEmpty(Foo *list);
void printList(Foo *list);
void coolfun(struct Foo * list, void (*fn)(void*), void *arg);
List *newitem(char * string, int data);
Foo * addfront(Foo *list, Foo * newp);
Foo * addend(Foo * list, Foo * newp);
Foo * copyList(Foo *list);
void reverseList(Foo** list);
void freeList(Foo *list);
void push(Foo ** list, int new_data);
void recursiveReverse(Foo** list);
void pushEnd(Foo ** list, int new_data);
void insertAfter(Foo * list, int new_data, int number);
void delByID(Foo **list, int position);
Foo* mergeList(Foo * a, Foo * b); // function that returns a pointer to merged list
BinaryTree *addToBTree(int data);
void inorder(BinaryTree * tree);
void deleteTree(BinaryTree *tree);
bool checkBalance(BinaryTree *tree);
int height(BinaryTree * tree);// function that returns weight of given node
void inOrderTraverse(BinaryTree *tree, void (*fn)(BinaryTree *, void*), void *arg);
BinaryTree * lookup(BinaryTree *btree, int data);
BinaryTree * nrlookup(BinaryTree *btree, int data);
void freeListForTask(List * list);
void delByIDForTask(List ** list, int position);
void printMembers(List *list);
void breakList(Foo ** list, Foo * firstNode, Foo *secondNode, int position);
unsigned int hash(char *str);
List * lookupHash(char *string, int create, int value);
unsigned int hsh(char *str, int mltplr);
List * lookupHsh(char *string, int create, int value, int mltplr);
void treesort(BinaryTree * tree);
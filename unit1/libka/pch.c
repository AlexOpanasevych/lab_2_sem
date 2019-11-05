/*C file for functions bodies*/
#include "pch.h"
#define max(a, b) (a >= b) ? a : b;

bool isEmpty(Foo *list){
    if(list == NULL) return true;
    else return false;
}

void printList(Foo *list){
    do{
        printf(" %d ", list->data);
        list = list->next;
    }while(list != NULL);
}

List *newitem(char *string, int data){
    List * newp;
    newp = (List*)malloc(sizeof(List));
    newp->data = data;
    strcpy(newp->string, string);
    newp->next = NULL;
    return newp;
}

Foo * addfront(Foo *list, Foo * newp){
    newp->next = list;
    return newp;
}

Foo * addend(Foo * list, Foo * newp){
    if(list == NULL) return newp;
    Foo *p;
    for(p = list; p->next !=NULL ; p=p->next){
        p->next = newp;
    }
    return newp;
}

void coolfun(Foo * list, void (*fn)(void*), void *arg){ // for task 8
    do{
        (*fn)(arg);
        list = list->next;
    }while(list);
}

Foo * copyList(Foo *list){
    if(!list) return NULL;
    Foo *temp=(Foo*)malloc(sizeof(Foo));
    temp->data=list->data;
    temp->next=copyList(list->next);
    return temp;
}

void freeList(Foo * list){
    Foo *temp;
    while(!isEmpty(list)){
        temp = list;
        list = list->next;
        free(temp);
    }
}

void freeListForTask(List * list){ // for task 11
    List * temp;
    while(list){
        temp = list;
        list = list->next;
        free(temp->string);
        free(temp);
    }
}

void reverseList(Foo** list) 
{ 
    Foo* prev   = NULL; 
    Foo* current = *list; 
    Foo* next = NULL; 
    while (current != NULL) {
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }
    *list = prev;
}

void push(Foo** list, int new_data) { 
    Foo* new_node = (Foo*) malloc(sizeof(Foo));            
    new_node->data  = new_data; 
    new_node->next = (*list);     
    (*list)    = new_node; 
}

void pushEnd(Foo ** list, int new_data) { 
    Foo* new_node = (Foo*) malloc(sizeof(Foo));
    Foo* last = *list;
    new_node->next = NULL;
    new_node->data = new_data;
    if(isEmpty(*list)) {*list = new_node; return;}
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void recursiveReverse(Foo** list) { 
    Foo* first; 
    Foo* rest;
    if (*list == NULL) return;
    first = *list;   
    rest  = first->next;
    if (!rest) return;    
    recursiveReverse(&rest); 
    first->next->next = first;   
    first->next  = NULL;           
    *list = rest;
}

void insertAfter(Foo * list, int new_data, int position){
    Foo* new_node = (Foo*) malloc(sizeof(Foo));
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

void delByID(Foo **list, int position){
    if (*list == NULL) return; 
    Foo * temp = *list; 
    if (position == 0) { 
        *list = temp->next;    
        free(temp);                
        return; 
    } 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next;
    if (temp == NULL || temp->next == NULL) return; 
    Foo *next = temp->next->next;  
    free(temp->next);
    temp->next = next; 
}

BinaryTree *addToBTree(int data){
    BinaryTree *btree = (BinaryTree*)malloc(sizeof(BinaryTree));
    btree->data = data;
    btree->left = NULL;
    btree->right = NULL;
    return btree;
}

void deleteTree(BinaryTree *tree){
    if (!tree) return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
}

void inorder(BinaryTree * tree) { 
    if (!tree) return;
    inorder(tree->left);
    printf(" %d ", tree->data);
    inorder(tree->right);
}

bool checkBalance(BinaryTree *tree){
    int lh;
    int rh;
    if (!tree) {
        return true;
    }
    lh = height(tree->left); 
    rh = height(tree->right);
    if(abs(lh - rh) <= 1 && checkBalance(tree->left) && checkBalance(tree->right))
        return true;
    return 0;
}

int height(BinaryTree * tree) {
    if(!tree) return 0; 
    return 1 + max(height(tree->left), height(tree->right)); 
}

void inOrderTraverse(BinaryTree *tree, void (*fn)(BinaryTree *, void*), void *arg){
    if(!tree) return;
    inOrderTraverse(tree->left, fn, arg);
    (*fn)(tree, arg);
    inOrderTraverse(tree->right, fn, arg);
}

Foo* mergeList(Foo * a, Foo * b) { 
    Foo* result = NULL;
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

int addname(gArray newname){
    gArray *nvp;
    if (nvtab.garray == NULL) {
        nvtab.garray = (gArray*)malloc(sizeof(gArray));
        if (nvtab.garray == NULL) return -1;
        nvtab.max = GINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) {
        nvp = (gArray*)realloc(nvtab.garray, (GGROW*nvtab.max)*sizeof(gArray));
        if(nvp == NULL) return -1;
        nvtab.max *= GGROW;
        nvtab.garray = nvp;
    }
    nvtab.garray[nvtab.nval] = newname;
    return nvtab.nval++;
}

BinaryTree * lookup(BinaryTree *btree, int data){
    if(!btree || data == btree->data) return btree;
    if(data < btree->data) return lookup(btree->left, data);
    else return lookup(btree->right, data);
}

BinaryTree * nrlookup(BinaryTree *btree, int data){
    while(btree){
        if(btree->data == data) return btree;
        else if(data < btree->data) btree = btree->left;
        else btree = btree->right; 
    }
    return NULL;
}

void delByIDForTask(List ** list, int position){
    if (*list == NULL) return; 
    List * temp = *list; 
    if (position == 0) { 
        *list = temp->next;
        //free(temp->string); 
        free(temp);                
        return; 
    }
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next;
    if (temp == NULL || temp->next == NULL) return; 
    List *next = temp->next->next;
    //free(temp->next->string);  
    free(temp->next);
    temp->next = next; 
}

void printMembers(List *list){
    do{
        printf("%d %s ", list->data, list->string);
        list = list->next;
    }while(list != NULL);
}

void breakList(Foo ** list, Foo * firstNode, Foo *secondNode, int position){
    if(isEmpty(*list)) return;
    firstNode = secondNode = (Foo*)malloc(sizeof(Foo));
    //firstNode = *;
    if(position == 0){
        secondNode = (*list)->next;
        firstNode->data = secondNode->data;
        //freeList(firstNode->next);
        firstNode->next = NULL;
        return;
    }
    //for(int i = 0; i < position - 1)
}

unsigned int hash(char *str){
    unsigned int h = 0;
    unsigned char *p;
    for(p = (unsigned char*)str; *p != '\0'; p++) h = MULTIPLIER*h + *p;
    return h % SIZE;
}

List * lookupHash(char *string, int create, int value){
    List * sym;
    int h = hash(string);
    for(sym = symtab[h]; sym; sym=sym->next)
        if(strcmp(string, sym->string) == 0) return sym;
    if(create) {
        sym = (List*)malloc(sizeof(List));
        sym->string = string;
        sym->data = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}
unsigned int hsh(char *str, int mltplr){
    unsigned int h = 0;
    unsigned char *p;
    for(p = (unsigned char*)str; *p != '\0'; p++) h = mltplr*h + *p;
    return h % SIZE;
}

List * lookupHsh(char *string, int create, int value, int mltplr){
    List * sym;
    int h = hsh(string, mltplr);
    for(sym = symtab[h]; sym; sym=sym->next)
        if(strcmp(string, sym->string) == 0) return sym;
    if(create) {
        sym = (List*)malloc(sizeof(List));
        sym->string = string;
        sym->data = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

void treesort(BinaryTree * tree){
    if(!tree) return;
    treesort(tree->left);
    if(!tree->left && !tree->right) return;
    treesort(tree->right);
}
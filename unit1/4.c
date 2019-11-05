/* ----------------------------------------------------------------<Header>-
 Name: 4.c
 Title: Задача 1.4.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Обратите внимание, что в коде Unit 1 "Growing Arrays" не употребляется такая
конструкция:
nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max) * sizeof(Nameval));
В этом случае, если бы при перераспределении памяти произошла ошибка, все
накопленные в исходном массиве данные были бы потеряны. Объясните почему?
Покажите действующий пример.
ответ снизу
 ------------------------------------------------------------------</Header>-*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
};

struct NVtab {
  int nval;
  int max;
  Nameval *nameval;
} nvtab;

enum {NVINIT = 1,NVGROW = 2};

/*addname*/
int addname(Nameval newname) {
  Nameval *nvp;
  if(nvtab.nameval == NULL) {
     nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
     if(nvtab.nameval == NULL)
         return -1;
     nvtab.max = NVINIT;
     nvtab.nval = 0; 
  } else if(nvtab.nval >= nvtab.max) {
    nvp = (Nameval *) realloc(nvtab.nameval,
                (NVGROW*nvtab.max)*sizeof(Nameval));
    if(nvp == NULL)
      return -1;
    nvtab.max *=NVGROW;
    nvtab.nameval = nvp;
  }
  nvtab.nameval[nvtab.nval] = newname;
  return nvtab.nval++;
}

/*delname*/
int delname(char *name) {
  for(int i=0; i<nvtab.nval;i++)
    if(strcmp(nvtab.nameval[i].name,name) == 0) {
      memmove(nvtab.nameval+i, nvtab.nameval+i+1,
        (nvtab.nval-(i+1))*sizeof(Nameval));
      nvtab.nval--;
      return 1;
    }
  return 0;
}

int main(void) {
  int curnum = addname((struct Nameval) {.name="Andy", .value=12});
  printf("%d\n", curnum);
  curnum = addname((struct Nameval) {.name="Billy", .value=18});
  printf("%d\n", curnum);
  for(int i=0;i<nvtab.nval; i++) {
    printf("%s %d\n",nvtab.nameval[i].name,
             nvtab.nameval[i].value);
  }
  return 0;
}

// при вызове realloc сразу для основного массива память может не выделиться, 
// и тогда данные в нем могут потеряться. В данном случае использование дополнительного массива
// предотвращает потерю данных. В случае ошибки при выделении памяти мы не теряем данные.
/* ----------------------------------------------------------------<Header>-
 Name: 1.c
 Title:  Задача 1.1.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description: Переменная struct NVtab {...} nvtab является глобальной. Модифицируйте
функции addname и delname (см. Unit 1 "Growing Arrays") так, чтобы в теле этих функций
устранить использование глобальной переменной nvtab.
 ------------------------------------------------------------------</Header>-*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
};

typedef struct NVtab NVtab;

struct NVtab {
  int nval;
  int max;
  Nameval *nameval;
};

enum {NVINIT = 1,NVGROW = 2};

/*addname*/
int addname(Nameval newname, NVtab *nvtab) {
  Nameval *nvp;
  if(nvtab->nameval == NULL) {
     nvtab->nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
     if(nvtab->nameval == NULL)
         return -1;
     nvtab->max = NVINIT;
     nvtab->nval = 0; 
  } else if(nvtab->nval >= nvtab->max) {
    nvp = (Nameval *) realloc(nvtab->nameval,
                (NVGROW*nvtab->max)*sizeof(Nameval));
    if(nvp == NULL)
      return -1;
    nvtab->max *=NVGROW;
    nvtab->nameval = nvp;
  }
  nvtab->nameval[nvtab->nval] = newname;
  return nvtab->nval++;
}

int main(void) {
    NVtab *nvtab /* = (NVtab*)malloc(sizeof(NVtab))*/;
    int curnum = addname((struct Nameval) {.name="Andy", .value=12}, nvtab);
    printf("%d\n", curnum);
    curnum = addname((struct Nameval) {.name="Billy", .value=18}, nvtab);
    printf("%d\n", curnum);
    for(int i=0;i<nvtab->nval; i++) {
        printf("%s %d\n",nvtab->nameval[i].name, nvtab->nameval[i].value);
    }
    return 0;
}
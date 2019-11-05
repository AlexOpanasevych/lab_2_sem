/* ----------------------------------------------------------------<Header>-
 Name: 6.c
 Title: Задача 1.6.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Внесите необходимые изменения в код функции addname и delname (см. Unit 1
"Growing Arrays") так, чтобы удалять имена, помечая их как неиспользуемые. Насколько 
остальная часть программы изолирована от этих изменений?
ответ : она полностью изолирована от этих изменений
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

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
  for (int i = 0; i < nvtab->nval; i++){
    if(nvtab->nameval[i].name == NULL){
        nvtab->nameval[i] = newname;
        return nvtab->nval;
    }
  }
  nvtab->nameval[nvtab->nval] = newname;
  return nvtab->nval++;
}

int delname(char *name, NVtab *nvtab) {
  for(int i=0; i<nvtab->nval;i++)
    if(strcmp(nvtab->nameval[i].name, name) == 0) {
      //memmove(nvtab->nameval+i, nvtab->nameval+(nvtab->nval), sizeof(Nameval));
      nvtab->nameval[i].name = NULL;
      nvtab->nval--;
      return 1;
    }
  return 0;
}

int main(void) {
    NVtab *nvtab = (NVtab*)malloc(sizeof(NVtab));
    int curnum = addname((struct Nameval) {.name="Andy", .value=12}, nvtab);
    printf("%d\n", curnum);
    curnum = addname((struct Nameval) {.name="Billy", .value=18}, nvtab);
    printf("%d\n", curnum);
    for(int i=0;i<nvtab->nval; i++) {
        printf("%s %d\n",nvtab->nameval[i].name, nvtab->nameval[i].value);
    }
    delname("Billy", nvtab);
    
    for(int i=0;i<nvtab->nval; i++) {
        printf("%s %d\n",nvtab->nameval[i].name, nvtab->nameval[i].value);
    }
    curnum = addname((struct Nameval) {.name="Sally", .value=19}, nvtab);
    printf("%d\n", curnum);

    return 0;
}
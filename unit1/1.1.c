/* ----------------------------------------------------------------<Header>-
 Name: 1.1.c
 Title: Модифицировать функции addname, delname.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-15
 Revised: 
 Description: Объяснить почему не вызывается realloc в delname.
 Ответ внизу..
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

/*delname*/
int delname(char *name, NVtab *nvtab) {
  for(int i=0; i<nvtab->nval;i++)
    if(strcmp(nvtab->nameval[i].name,name) == 0) {
      memmove(nvtab->nameval+i, nvtab->nameval+i+1, (nvtab->nval-(i+1))*sizeof(Nameval));
      nvtab->nval--;
      return 1;
    }
  return 0;
}

int main(void) {
  return 0;
}
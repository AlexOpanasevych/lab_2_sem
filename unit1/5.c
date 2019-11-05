/* ----------------------------------------------------------------<Header>-
 Name: 5.c
 Title: Задача 1.5.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Удаление имени из массива требует решить что делать с освободившейся
ячейкой. Если порядок элементов не имеет значения, то легче всего перебросить
последний элемент в образовавшуюся свободную позицию. Если же порядок необходимо
соблюсти, то придется сдвинуть на одну ячейку назад все элементы после свободной
позиции. Именно так поступает функция delname (см. Unit 1 "Growing Arrays").
Покажите на действующем примере переброску последнего элемента в образовавшуюся
свободную позицию.
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
  nvtab->nameval[nvtab->nval] = newname;
  return nvtab->nval++;
}

int delname(char *name, NVtab *nvtab) {
  for(int i=0; i<nvtab->nval;i++)
    if(strcmp(nvtab->nameval[i].name, name) == 0) {
      memmove(nvtab->nameval+i, nvtab->nameval+(nvtab->nval), sizeof(Nameval));
      nvtab->nval--;
      return 1;
    }
  return 0;
}

int main(void) {
    NVtab *nvtab /*= (NVtab*)malloc(sizeof(NVtab))*/;
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
    return 0;
}
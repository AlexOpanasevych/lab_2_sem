/* ----------------------------------------------------------------<Header>-
 Name: 18.c
 Title: Задача 1.18.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Каким должен быть размер массива symtab (см. Unit 1 "Hash Table")? Общая
идея состоит в том, что массив symtab должен быть достаточно велик, чтобы цепочка
каждого хэш-кода содержала поменьше элементов, и операция поиска имела характер
0(1). Свой ответ подкрепите примером кода.
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

const unsigned char n_begin = 'A';
const unsigned char n_end = 'Z';
const size_t str_len = 3;

int next_element(char *str, size_t strlen) {
	size_t index = strlen - 1;
	int cond = 0;
	while(!cond) {
		cond = 1;
		if(++str[index] > n_end) {
			if (index == 0) {
				return 0;
			}
			str[index--] = n_begin;
			cond = 0;
		}
	}
	return 1;
}

int main(){
    List * node;
    char *str = (char*)malloc((str_len+1)*sizeof(char));
	memset(str, n_begin, str_len);
	str[str_len] = 0;
	int count = 0;
	do {
		node = lookupHash(str, 1, count);
		printf(" %d %s ", node->data, node->string);
		count++;
	} while(next_element(str, str_len));
	freeListForTask(node);
    return 0;
}

// размер массива symtab должен быть большим простым числом, в этом примере 30011, при этом ключ и значение, вычисляемое хэш-функцией, не будут пересекаться
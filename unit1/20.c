/* ----------------------------------------------------------------<Header>-
 Name: 20.c
 Title: Задача 1. 20.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Хэш-функция (см. Unit 1 "Hash Table") имеет довольно общий характер и
удобна при работе со строками. Однако с некоторыми исходными данными она может
справляться недостаточно эффективно. Сконструируйте набор данных, который бы
заставил эту функцию работать плохо. Насколько трудно построить такой набор для
различных значений NHASH?
 ------------------------------------------------------------------</Header>-*/
#include "libka/pch.h"

const unsigned char n_begin = 118;
const unsigned char n_end = 150;
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
    //node = lookupHash(str, 0, 115);
	freeListForTask(node);
    return 0;
}

// для того, чтобы заставить хэш-функцию работать плохо, можно использовать сложные символы ASCII, для больших значений Nhash такой набор построить труднее
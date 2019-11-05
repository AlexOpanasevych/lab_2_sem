/* ----------------------------------------------------------------<Header>-
 Name: 19.c
 Title: Задача 1.19.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-15
 Revised: 
 Description:  Хэш-функция, хорошо работающая с данными одного вида (например,
короткими именами переменных), может оказаться неудачной в работе с другими (такими
как URL-адреса), поэтому хэш-функцию для своей программы следует тестировать на
типичных наборах входных данных. Хорошо ли она кодирует короткие строки? А длинные?
А строки одинаковой длины с небольшими отличиями? Сгенерируйте поток данных для
заполнения хэша и проверьте качество хэширования (длины цепочек) при MULTIPLIER от
31 до 37.
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


int main(void){
    List *node;
    char *str = (char*)malloc((str_len+1)*sizeof(char));
    for(int i = MULTIPLIER; i <=37; i++){
        memset(str, n_begin, str_len);
	    str[str_len] = 0;
	    int count = 0;
        do {
		    node = lookupHsh(str, 1, count, i);
            //printf(" %d %s ", node->data, node->string);// you can uncomment to see what is in node
		    count++;
	    } while(next_element(str, str_len));
    }
	freeListForTask(node);
    return 0;
}
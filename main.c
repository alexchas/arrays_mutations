#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE_A 1024
#define SIZE_F 256
#define SIZE_M 256

u_int8_t myswap(u_int8_t *arr, u_int8_t *a, u_int8_t *b);

u_int8_t myswap(u_int8_t *arr, u_int8_t *a, u_int8_t *b) {              // библиотечные алгоритмы использовать нельзя, поэтому делаю myswap
    u_int8_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int main() {
    u_int8_t *array_a, *array_f, *array_m, val_index_f, out_val_f, buf;
    int pos, npos;

    array_a = malloc(SIZE_A * sizeof(u_int8_t));
    array_f = malloc(SIZE_F * sizeof(u_int8_t));
    array_m = malloc(SIZE_M * sizeof(u_int8_t));

    // заполнение массива А случайными значениями
    printf("Сгенерированный массив А: \n");
    for(int i = 0; i < SIZE_A; i++) {
        array_a[i] = rand() % 256;                                      // диапазон случайных значений 0-255
        printf("%d ", array_a[i]);
    }

    // заполнение массива F уникальными случайными значениями
    memset(array_f, -1, SIZE_F);
    printf("Сгенерированный массив F уникальных значений: \n");
    for(pos = 0; pos < SIZE_F - 1;  ) {
        npos = random() % SIZE_F;                               // рандомное значение от pos до SIZE_F
        if(array_f[npos] == -1) {
            array_f[npos] = pos;
        } else if(array_f[pos] == -1) {
            array_f[pos] = array_f[npos];
            array_f[npos] = pos;
        } else {
            myswap(array_f, pos, npos);                                   // замена местами
            continue;
        }
        pos++;
        printf("%d ", array_f[pos]);
    }

    if((sizeof(array_a) % 256) !=0) {                                   // сгенерированный рандомный массив не кратен 256-ти
       buf = 256-(sizeof(array_a) % 256);                               // количество байтов, которое необходимо дополнить 0-ми значениями.
       array_a = (u_int8_t*)realloc(array_a, buf*sizeof(u_int8_t));    // изменяем размер блока выделенной памяти на количество байтов дополненных 0-ми
    }
    // получение массива перестановок "B"
    for(u_int8_t i=0; i<SIZE_M; i++) {                 // проход по индексам массива M[256] для получения значений по индексу для формирования перестановочного массива
        val_index_f = array_a[i];                      // val_index_f - значение элемента массива A[i]
        out_val_f = array_f[i];                        // out_val_f - значение i-го элемента эталонного массива F, которое станет индексом в результирующем M
        array_m[out_val_f] = array_a[i];
        printf("%d ", array_m[i]);
    }
    u_int8_t len = sizeof(array_m);                                       // длина полученного массива
    memcpy(array_m + 4 * sizeof(u_int8_t), array_m, sizeof(array_m));     // перемещение всего массива вправо на 4 байта для вставки значения его длины в начало массива
    memcpy(array_m + sizeof(len), len, sizeof(len));                      // запись длинны массива в начало

    free(array_a);
    free(array_f);
    free(array_m);
    return 0;
}

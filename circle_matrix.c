#include "circle_matrix.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "config.h"

/*
Матрица представляет собой круг с центром в точке (r; r) и радиусом r
Если передан массив, в котором элементов больше, чем может быть в круге
заданного радиуса, лишние элементы будут игнорироваться
Если в массиве элементов меньше, чем нужно кругу заданного радиуса,
ожидается неопределенное поведение
КОНТРОЛЬ ЗА КОЛИЧЕСТВОМ ЭЛЕМЕНТОВ МАССИВА ОСТАЕТСЯ ЗА ПРОГРАММИСТОМ
ПОЖАЛУЙСТА НЕ БУДЬТЕ ПОГРОМИСТАМИ
*/

/*
Возвращает память из кучи с 4r+2 элементами - (2r+1) пара чисел (a, b)
где n-я пара - границы допустимых индексов для колонок n-го ряда,
т.е. такие a и b, что a <= x <= b
*/
static size_t *get_indexes_limit(size_t r)
{
    size_t *p = (size_t *)calloc(4 * r + 2, sizeof(size_t));
    if (!p)
        return NULL;

    double root = 0;
    double a = 0, b = 0;

    for (size_t n = 0; n < 2 * r + 1; n++)
    {
        root = sqrt(2 * n * r - n * n);
        a = ceil((double)r - root);
        b = floor((double)r + root);
        printf("n = %zu, a = %f, b = %f\n", n, a, b);
        p[2 * n] = (size_t)a;
        p[2 * n + 1] = (size_t)b;
    }
    return p;
}

int *circle_get_el(int *matrix, size_t r, size_t x, size_t y)
{
    // точка должна находится внутри круга
    assert(((x - r) * (x - r) + (y - r) * (y - r) <= r * r) && "Точка находится вне круга");

    size_t sm = 0;
    size_t *p = get_indexes_limit(r);
    assert(p);

    for (size_t i = 0; i < y; i++)
        sm += p[2 * i + 1] - p[2 * i] + 1;

    printf("sm = %lu\n", sm);

    free(p);

    return &matrix[sm + x];
}

void circle_put_el(int *matrix, size_t r, size_t x, size_t y, int value)
{
    *circle_get_el(matrix, r, x, y) = value;
}

void circle_print_matrix(int *matrix, size_t r)
{
    size_t *p = get_indexes_limit(r);
    assert(p);
    size_t a = 0, b = 0;

    size_t sm = 0;
    unsigned padding_koeff = 2;

    for (size_t y = 0; y < 2 * r + 1; y++)
    {
        a = p[2 * y];
        b = p[2 * y + 1];

        for (size_t i = 0; i < padding_koeff * a; i++)
        {
            assert(y != r);
            printf(" ");
        }

        for (size_t x = 0; x <= b - a; x++)
        {
            printf("%d", matrix[sm + x]);
            // printf("%s[%zu][%zu]%s = %s%d%s", RED_COLOR, y, x, RESET_COLOR,
            //        GREEN_COLOR, matrix[sm + x], RESET_COLOR);
            printf(" ");
        }
        sm += b - a + 1;
        printf("\n");
    }
}
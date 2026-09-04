#include "triangle_matrix.h"
#include <stdio.h>
#include <assert.h>
#include "config.h"

static void swap(size_t *a, size_t *b)
{
    assert(a);
    assert(b);

    size_t temp = *a;
    *a = *b;
    *b = temp;
}

int *tr_get_el(int *matrix, size_t size, size_t x, size_t y)
{
    assert(matrix);
    assert(size > 1);
    assert(x != y && "y не может быть равен x!");

    // y всегда больше, так как матрица треугольная
    if (x > y)
        swap(&x, &y);

    assert(y <= size - 1);

    return &matrix[y * (y - 1) / 2 + x];
}

void tr_put_el(int *matrix, size_t size, size_t x, size_t y, int value)
{
    assert(matrix);
    assert(size > 1);
    assert(x != y && "y не может быть равен x!");

    *tr_get_el(matrix, size, x, y) = value;
}

void tr_print_matrix(int *matrix, size_t size)
{
    assert(matrix);
    assert(size > 1);

    for (size_t y = 1; y < size; y++)
    {
        for (size_t x = 0; x < y; x++)
        {
            printf("%s[%zu][%zu]%s = %s%d%s", RED_COLOR, y, x, RESET_COLOR,
                   GREEN_COLOR, *tr_get_el(matrix, size, x, y), RESET_COLOR);
            printf(" ");
        }
        printf("\n");
    }
}
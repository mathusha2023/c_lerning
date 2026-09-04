#include "matrix.h"
#include <stdio.h>
#include <assert.h>
#include "config.h"

int *get_el(int *matrix, size_t width, size_t x, size_t y)
{
    assert(matrix);

    return &matrix[y * width + x];
}

void print_matrix(int *matrix, size_t width, size_t height)
{
    assert(matrix);

    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            printf("%s[%zu][%zu]%s = %s%d%s", RED_COLOR, y, x, RESET_COLOR,
                   GREEN_COLOR, *get_el(matrix, width, x, y), RESET_COLOR);
            printf(" ");
        }
        printf("\n");
    }
}

void sum_matrix(int *m1, int *m2, int *res_m, size_t width, size_t height)
{
    assert(m1);
    assert(m2);
    assert(res_m);

    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            int a = *get_el(m1, width, x, y);
            int b = *get_el(m2, width, x, y);
            *get_el(res_m, width, x, y) = a + b;
        }
    }
}

void multiply_matrix_to_number(int *matrix, size_t width, size_t height, int value)
{
    assert(matrix);

    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            *get_el(matrix, width, x, y) *= value;
        }
    }
}
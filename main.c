#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "my_strings.h"
#include "matrix.h"
#include "triangle_matrix.h"

void print_rt(int *matrix)
{
}

int main()
{
    const size_t size = 6;
    int arr[] = {0,
                 1, 2,
                 3, 4, 5,
                 6, 7, 8, 9,
                 10, 11, 12, 13, 14};

    // проверка для корректных размеров массива
    assert(sizeof arr / sizeof arr[0] == size * (size - 1) / 2);

    tr_print_matrix(arr, size);
    printf("\nChanging element...\n");

    tr_put_el(arr, size, 0, 4, 1488);

    printf("Successful changed\n");
    tr_print_matrix(arr, size);

    return 0;
}

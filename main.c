#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "config.h"
#include "my_strings.h"
#include "matrix.h"
#include "triangle_matrix.h"
#include "circle_matrix.h"

int main()
{
    disable_line_break();
    // const size_t size = 6;
    // int arr[] = {0,
    //              1, 2,
    //              3, 4, 5,
    //              6, 7, 8, 9,
    //              10, 11, 12, 13, 14};

    // // проверка для корректных размеров массива
    // assert(sizeof arr / sizeof arr[0] == size * (size - 1) / 2);

    // tr_print_matrix(arr, size);
    // printf("\nChanging element...\n");

    // tr_put_el(arr, size, 0, 4, 1488);

    // printf("Successful changed\n");
    // tr_print_matrix(arr, size);

    const size_t r = 10;
    int arr[1000] = {};

    circle_print_matrix(arr, r);
    printf("\n");

    circle_put_el(arr, r, 5, 3, 9);

    circle_print_matrix(arr, r);

    enable_line_break();
    return 0;
}

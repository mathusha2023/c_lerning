#include <stddef.h>

int *tr_get_el(int *matrix, size_t size, size_t x, size_t y);
void tr_put_el(int *matrix, size_t size, size_t x, size_t y, int value);
void tr_print_matrix(int *matrix, size_t size);
#include <stddef.h>

// полные копии стандартных функций
size_t mystrlen(const char *s);
int myputs(const char *s);
char *mystrcpy(char *dest, const char *src);
char *mystrcat(char *dest, const char *src);
int mystrcmp(const char *s1, const char *s2);
char *mystrchr(const char *s, int ch);
char *mystrstr(const char *s, const char *needle);
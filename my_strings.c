#include <stdio.h>
#include <assert.h>

size_t mystrlen(const char *s)
{
    assert(s);

    size_t i = 0;
    for (i = 0; s[i]; i++)
        ;
    return i;
}

int myputs(const char *s)
{
    assert(s);

    for (int i = 0; s[i]; i++)
    {
        if (putchar(s[i]) == EOF)
            return EOF;
    }
    return putchar('\n');
}

char *mystrcpy(char *dest, const char *src)
{
    assert(dest);
    assert(src);

    int i = 0;
    for (i = 0; (dest[i] = src[i]); i++)
        ;
    dest[i] = '\0';
    return dest;
}

char *mystrcat(char *dest, const char *src)
{
    assert(dest);
    assert(src);

    char *destcpy = dest;

    while (*dest)
        dest++;

    for (int i = 0; src[i]; i++)
        *dest++ = src[i];

    *dest = '\0';
    return destcpy;
}

int mystrcmp(const char *s1, const char *s2)
{
    assert(s1);
    assert(s2);

    int i = 0;
    for (i = 0; s1[i] && s2[i]; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}

char *mystrchr(const char *s, int ch)
{
    assert(s);

    size_t i = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == ch)
            return (char *)(s + i);
    }
    return NULL;
}

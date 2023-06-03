#include <stdio.h>

/* copy input to output; 1st version */
main()
{
    int c;
    printf("%d", EOF);
    while ((c = getchar()) != EOF)
    {
        // int result = c != EOF;
        printf("\n%d\n", c != EOF);
        putchar(c);
    }
}
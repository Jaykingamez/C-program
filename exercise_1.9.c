#include <stdio.h>

/* Copy input to output, replace multiple blanks with single blanks */
main()
{
  int c;
  int isblank = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' && isblank == 0)
    {
      isblank = 1;
      putchar(c);
    }

    else if (c == ' ' && isblank == 1)
      ;
    else
    {
      isblank = 0;
      putchar(c);
    }
  }
}
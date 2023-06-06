#include <stdio.h>
#define MAXLINE 1000  /* maximum input line size */
#define NOTTRAILING 0 /* Character is not a blank/tab*/
#define TRAILING 1    /* Trailing Blank/Tab */

int fgetline(char line[], int maxline);

/* print longest input line */
int main()
{
  int len;            /* current line length */
  int max;            /* maximum length seen so far */
  char line[MAXLINE]; /* current input line */

  while ((len = fgetline(line, MAXLINE)) > 0)
  {
    if (len > 2)
      printf("%s", line);
  }
  return 0;
}

/* getline: read a line into s, return length */
int fgetline(char s[], int lim)
{
  int c, i, state;
  state = NOTTRAILING;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    if (c != ' ' && c != '\t')
    {
      state = NOTTRAILING;
    }
    if (i < lim - 1 && state == NOTTRAILING)
    {
      s[i] = c;
      i++;
    }

    if (c == ' ' || c == '\t')
      state = TRAILING;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
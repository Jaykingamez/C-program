#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int fgetline(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
int main()
{
  int len;                     /* current line length */
  int max;                     /* maximum length seen so far */
  char line[MAXLINE];          /* current input line */
  char reversed_line[MAXLINE]; /*reversed input line */

  while ((len = fgetline(line, MAXLINE)) > 0)
  {
    reverse(line); // reverse line
    printf("%s", line);
  }
  return 0;
}

/* getline: read a line into s, return length */
int fgetline(char s[], int lim)
{
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    if (i < lim - 1)
    {
      s[i] = c;
      i++;
    }
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* reverse: read a line and reverse the line */
void reverse(char line[])
{
  char reverse[MAXLINE];

  int length;

  // printf("String: %s\n", line);

  // get length of line
  for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++)
    length = i;
  // printf("Length: %d\n", length);
  //  set the end of reverse line
  reverse[length + 1] = '\0';

  int counter = 0;
  // reverse the input line
  for (int i = length; i >= 0; i--)
  {
    reverse[counter] = line[i];
    counter++;
  }

  // reverse the line
  for (int i = 0; i <= length; i++)
    line[i] = reverse[i];
}
